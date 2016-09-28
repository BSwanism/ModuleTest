#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
int a;
char *str;
module_param(a, int, 0);
module_param(str, charp,0);
int __init init_param(void){
  printk("module message : param\n");
  printk("module message param a:%d\n",a);
  printk("module message param str:%s\n",str);
  return 0;
}
void __exit exit_param(void){
  printk("module message : param module stop\n");
}
module_init(init_param);
module_exit(exit_param);
MODULE_LICENSE("GPL");
