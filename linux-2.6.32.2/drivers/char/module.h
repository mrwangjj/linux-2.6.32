#ifndef  _MODULE_H_
#define  _MODULE_H_

#include "newled.h"

 extern int my_register_dev(struct my_device *pdev);
 extern void my_setup_cdev(struct my_device *pdev);
 extern void my_create_class(struct my_device *pdev);
 
 
#endif
