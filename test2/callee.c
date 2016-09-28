#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
int __init init_callee(void){
  printk("module message : callee\n");
  return 0;
}
void __exit exit_callee(void){
  printk("module message : callee module stop\n");
}
int add(int a, int b){
  printk("module message : callee module add\n");
  return a+b;
}
int sub(int a, int b){
  printk("module message : callee module sub\n");
  return a-b;
}
EXPORT_SYMBOL(add);
EXPORT_SYMBOL(sub);
module_init(init_callee);
module_exit(exit_callee);
MODULE_LICENSE("GPL");
