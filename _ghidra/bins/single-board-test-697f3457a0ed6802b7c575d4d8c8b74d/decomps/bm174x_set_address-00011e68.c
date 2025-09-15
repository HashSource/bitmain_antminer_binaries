
void bm174x_set_address(int fd,uint8_t address)

{
  uint8_t address_local;
  int fd_local;
  
  address_local = address;
  fd_local = fd;
  bm174x_ioctl(fd,3,&address_local);
  return;
}

