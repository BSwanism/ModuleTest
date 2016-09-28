#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
int b[]={1,2,3,4,5};
module_param_array(b, int, NULL,0);
int __init init_param2(void){
  printk("module message : param2\n");
  printk("module message param2 array: %d,%d,%d,%d,%d\n",b[0],b[1],b[2],b[3],b[4]);
  return 0;
}
void __exit exit_param2(void){
  printk("module message: param2 module stop\n");
}
module_init(init_param2);
module_exit(exit_param2);
MODULE_LICENSE("GPL");
