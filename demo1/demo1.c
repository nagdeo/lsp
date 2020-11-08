// Used for all kernel modules
#include<linux/kernel.h>

// Used for the module functionality
#include<linux/module.h>

// Get called when module gets loaded
int init_module(void)
{

   printk(KERN_INFO "Marvellous kernel module loaded\n");
   return 0;
}

// Get called when module gets unloaded
void cleanup_module(void)
{
    printk(KERN_INFO "Marvellous kernel module unloaded\n");
    return;

}


//printk() is a function to print in the kernel log file





/*

  steps to execute:

  simran@simran-Lenovo-IdeaPad-S145-15IWL:~$ make all
  simran@simran-Lenovo-IdeaPad-S145-15IWL:~$ sudo insmod demo2.ko
  simran@simran-Lenovo-IdeaPad-S145-15IWL:~$ lsmod                        //this command to see whether demo1 is inserted in kernel module
  simran@simran-Lenovo-IdeaPad-S145-15IWL:~$ sudo rmmod demo1             // to remove user define module from kernel module
  simran@simran-Lenovo-IdeaPad-S145-15IWL:~$ modinfo demo1.ko             // to see info


 

  

  


  
*/
