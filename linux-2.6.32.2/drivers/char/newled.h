#ifndef  _NEWLED_H_
#define  _NEWLED_H_

/*内核头文件*/
#include <linux/miscdevice.h>
#include <linux/delay.h>
#include <asm/irq.h>
#include <mach/regs-gpio.h>
#include <mach/hardware.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <linux/string.h>
#include <linux/list.h>
#include <linux/pci.h>
#include <linux/gpio.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <asm/unistd.h>

#include <linux/cdev.h>
#include <linux/device.h>


struct my_device 
{
   dev_t  dev_num; //设备号
   struct cdev cdev;  //字符设备结构
   struct file_operations my_fops; //文件操作
   struct class *p_class; //动态创建设备文件节点
};


#define   DEVICE_NAME    "newled"

#define   LED_OFF     0
#define   LED_ON      1

#endif