// Used for all kernel modules
#include<linux/kernel.h>

// Used for the module functionality
#include<linux/module.h>

#include<linux/moduleparam.h>
#include<linux/stat.h>

#define AUTHOR "Piyush Khairnar"
#define DESC "Demo kernel module of marvellous"

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);

int no=11;
module_param(no,int,S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// Get called when module gets loaded
int start(void)
{

   printk(KERN_INFO "Marvellous kernel module loaded %d\n",no);
   return 0;
}

// Get called when module gets unloaded
void end(void)
{
    printk(KERN_INFO "Marvellous kernel module unloaded\n");
  
}
module_init(start);
module_exit(end);
//printk() is a function to print in the kernel log file
