
void bm174x_send_work(int fd,uint8_t *buf)

{
  uint8_t *buf_local;
  int fd_local;
  
  bm174x_ioctl(fd,2,buf);
  return;
}

