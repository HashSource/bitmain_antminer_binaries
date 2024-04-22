
void bm174x_set_io_drive_strength(int fd,uint32_t value)

{
  uint32_t value_local;
  int fd_local;
  base_type_t item;
  
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '0';
  reg_value.io_drive_strength = value;
  item.data = value;
  bm174x_ioctl(fd,1,&item);
  return;
}

