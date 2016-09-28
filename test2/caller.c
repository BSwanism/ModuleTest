#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
int add(int, int);
int sub(int, int);
int __init init_caller(void){
  printk("module message : caller\n");
  printk("module message : add %d\n",add(2,3));
  printk("module message : sub %d\n",sub(3,1));
  return 0;
}
void __exit exit_caller(void){
  printk("module message : caller module stop\n");
}
module_init(init_caller);
module_exit(exit_caller);
MODULE_LICENSE("GPL");
