#ifndef  _NEWLED_H_
#define  _NEWLED_H_

/*�ں�ͷ�ļ�*/
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
   dev_t  dev_num; //�豸��
   struct cdev cdev;  //�ַ��豸�ṹ
   struct file_operations my_fops; //�ļ�����
   struct class *p_class; //��̬�����豸�ļ��ڵ�
};


#define   DEVICE_NAME    "newled"

#define   LED_OFF     0
#define   LED_ON      1

#endif