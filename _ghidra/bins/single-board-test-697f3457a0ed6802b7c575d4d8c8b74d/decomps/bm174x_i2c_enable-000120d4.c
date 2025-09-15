
void bm174x_i2c_enable(int fd,uint8_t chip_addr)

{
  uint8_t chip_addr_local;
  int fd_local;
  base_type_t item;
  bm174x_reg misc_reg;
  
  misc_reg.reg_bin = reg_value.misc_control | 0x4060;
  item.all = '\0';
  item.addr = '\x1c';
  item.data = misc_reg.reg_bin;
  item.chip_addr = chip_addr;
  bm174x_ioctl(fd,1,&item);
  return;
}

