#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<asm/uaccess.h>
#include<linux/slab.h>
static char *buffer =NULL;
int virtual_device_open(struct inode *inode, struct file *filp){
  printk(KERN_ALERT "virtual_device open\n");
  return 0;
}
int virtual_device_release(struct inode *inode, struct file *filp){
  printk(KERN_ALERT "virtual_device release\n");
  return 0;
}
ssize_t virtual_device_write(struct file*filp, const char *buf, size_t count,loff_t *f_pos){
  printk(KERN_ALERT "virtual_device write\n");
  strcpy(buffer,buf);
  return count;
}
ssize_t virtual_device_read(struct file*filp, const char *buf, size_t count,loff_t *f_pos){
  printk(KERN_ALERT "virtual_device read\n");
  copy_to_user(buf,buffer,1024);
  return count;
}
static struct file_operations vd_fops={
  .read= virtual_device_read,
  .write= virtual_device_write,
  .open= virtual_device_open,
  .release= virtual_device_release
};
int __init virtual_device_init(void){
  if(register_chrdev(213,"virtual_device",&vd_fops)<0)
    printk(KERN_ALERT "driver init failed\n");
  else
    printk(KERN_ALERT "driver init successful\n");
  buffer =(char*)kmalloc(1024,GFP_KERNEL);
  if(buffer!=NULL)
    memset(buffer,0,1024);
  return 0;
}
void __exit virtual_device_exit(void){
  unregister_chrdev(213,"virtual_device");
  kfree(buffer);
  printk(KERN_ALERT "driver exit successful\n");
}
module_init(virtual_device_init);
module_exit(virtual_device_exit);
MODULE_LICENSE("GPL");

