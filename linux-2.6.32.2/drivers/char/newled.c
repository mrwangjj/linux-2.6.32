/*************************************************
  Copyright (C), 2013-2022, Sangfor Tech. Co., Ltd.
  File name:  web-pwm.c
  Author:王金剑       Version:  V1.0      Date: 2013-5-11
  Description: PWM 驱动程序 :
  Others: 
  Function List:  
  History: no
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/


#include "newled.h"
#include "module.h"


/*存放要操作的IO口*/
static unsigned long led_table [] = {
	S3C2410_GPB(5),
	S3C2410_GPB(6),
	S3C2410_GPB(7),
	S3C2410_GPB(8),
};

/*IO要配置的模式*/
static unsigned int led_cfg_table [] = {
	S3C2410_GPIO_OUTPUT,
	S3C2410_GPIO_OUTPUT,
	S3C2410_GPIO_OUTPUT,
	S3C2410_GPIO_OUTPUT,
};




static int newled_ioctl(
	struct inode *inode, 
	struct file *file, 
	unsigned int cmd, 
	unsigned long arg)
{
	switch(cmd) {
	case 0:
	case 1:
		if (arg > 4) {
			return -EINVAL;
		}
		s3c2410_gpio_setpin(led_table[arg], !cmd);
		return 0;
	default:
		return -EINVAL;
	}
}

/*文件操作结构*/
struct my_device my_device = 
{
	.my_fops.owner = THIS_MODULE,
	.my_fops.ioctl = newled_ioctl,
};


static int newled_init(void)
{
	int ret  = 0;
	
	int i;
	
	for(i = 0; i < 4; i++)
	{
		s3c2410_gpio_cfgpin(led_table[i], led_cfg_table[i]);  //配置IO的模式
		s3c2410_gpio_setpin(led_table[i], LED_OFF);  //set all to low
	}

		/*设备注册*/
    my_register_dev(&my_device);
    my_setup_cdev(&my_device);
    my_create_class(&my_device);
		
			printk("My newled_driver Initialized ok! \n");

    return ret;
	  
} 

static void newled_exit(void)
{
	
}

module_init(newled_init);
module_exit(newled_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MrWang");