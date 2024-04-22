
int bm174x_ioctl(int fd,uint32_t oper_type,void *param)

{
  uint length;
  void *param_local;
  uint32_t oper_type_local;
  int fd_local;
  uint8_t str [300];
  int len;
  
  memset(str,0,300);
  length = bm174x_pack_ioctl_pkg(str,300,oper_type,param);
  if (-1 < (int)length) {
    length = uart_send((uchar)fd,str,length);
  }
  return length;
}

