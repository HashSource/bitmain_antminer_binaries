
void bm174x_read_register(int fd,int mode,uint8_t chip_addr,uint8_t reg_addr)

{
  uint8_t reg_addr_local;
  uint8_t chip_addr_local;
  int mode_local;
  int fd_local;
  base_type_t item;
  
  item.all = (uint8_t)mode;
  item.data = 0;
  item.chip_addr = chip_addr;
  item.addr = reg_addr;
  bm174x_ioctl(fd,0,&item);
  return;
}

