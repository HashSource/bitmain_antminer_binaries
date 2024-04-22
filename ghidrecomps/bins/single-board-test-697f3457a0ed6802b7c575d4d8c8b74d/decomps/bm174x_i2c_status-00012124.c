
void bm174x_i2c_status(int fd,uint8_t chip_addr)

{
  uint8_t chip_addr_local;
  int fd_local;
  base_type_t item;
  
  item.data = 0;
  item.all = '\0';
  item.chip_addr = chip_addr;
  item.addr = ' ';
  item._3_1_ = 0;
  bm174x_ioctl(fd,0,&item);
  return;
}

