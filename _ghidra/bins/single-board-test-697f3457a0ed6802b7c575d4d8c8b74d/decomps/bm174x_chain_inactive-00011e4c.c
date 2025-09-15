
void bm174x_chain_inactive(int fd)

{
  int fd_local;
  
  bm174x_ioctl(fd,4,(void *)0x0);
  return;
}

