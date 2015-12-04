
#include "module.h"
#include  "newled.h"

/*此函数用来申请设备号*/
 int my_register_dev(struct my_device *pdev)
{
   int ret = 0;
   
   ret = alloc_chrdev_region(&pdev->dev_num, 0, 1, DEVICE_NAME);
   if(ret < 0)
   {
   	  printk(KERN_DEBUG "Can't register device \n");
			return -1;
   }
   
   
}

/*字符设备的注册*/
 void my_setup_cdev(struct my_device *pdev)
{
	 int err;
   cdev_init(&pdev->cdev, &pdev->my_fops);
   pdev->cdev.owner  =  THIS_MODULE;
   pdev->cdev.ops    =  &pdev->my_fops;
   err = cdev_add(&pdev->cdev, pdev->dev_num, 1);
   if(err)
   {
   	  printk(KERN_DEBUG "Error cdev_add \n");
			return -1;
   }
}


/*动态创建设备文件节点*/
 void my_create_class(struct my_device *pdev)
{
		  pdev->p_class =  class_create(THIS_MODULE, DEVICE_NAME);
			device_create(pdev->p_class, NULL, MKDEV(MAJOR(pdev->dev_num), 0), NULL, DEVICE_NAME);
}


//EXPORT_SYMBOL(my_register_dev);
//EXPORT_SYMBOL(my_setup_cdev);
//EXPORT_SYMBOL(my_create_class);
