
void bm174x_write_register(int fd,int mode,uint8_t chip_addr,uint8_t reg_addr,uint32_t reg_data)

{
  uint8_t reg_addr_local;
  uint8_t chip_addr_local;
  int mode_local;
  int fd_local;
  base_type_t item;
  
  item.all = (uint8_t)mode;
  item.data = reg_data;
  item.chip_addr = chip_addr;
  item.addr = reg_addr;
  bm174x_ioctl(fd,1,&item);
  return;
}

