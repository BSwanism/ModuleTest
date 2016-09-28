#include<stdio.h>
#include<unistd.h>
#include<sys/fcntl.h>

int main(){
  int dev;
  char buff[1024];
  dev=open("/dev/virtual_device",O_RDWR);
  printf("dev:%d\n",dev);
  if(dev<0){
    printf("device open error\n");
    return -1;
  }
  write(dev,"1234",4);
  read(dev,buff,4);
  printf("read from device :%s\n",buff);
  close(dev);
  return 0;
}
