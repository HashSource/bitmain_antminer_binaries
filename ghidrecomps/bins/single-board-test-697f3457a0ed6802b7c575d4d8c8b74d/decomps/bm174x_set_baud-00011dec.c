
void bm174x_set_baud(int fd,int baudrate)

{
  uint32_t uVar1;
  byte bVar2;
  int baudrate_local;
  int fd_local;
  base_type_t item;
  bm174x_reg reg_misc;
  
  uVar1 = reg_value.misc_control;
  bVar2 = get_bt8d_from_baud(baudrate);
  reg_misc.core_timeout.core_timeout._1_1_ = (undefined)(uVar1 >> 8);
  reg_misc.core_timeout.core_timeout._2_2_ = (undefined2)(uVar1 >> 0x10);
  reg_misc.core_timeout.core_timeout._0_1_ = (undefined)uVar1;
  reg_misc.core_timeout.core_timeout._1_1_ =
       reg_misc.core_timeout.core_timeout._1_1_ & 0xe0 | bVar2 & 0x1f;
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '\x1c';
  item.data = reg_misc.reg_bin;
  reg_value.misc_control = reg_misc.reg_bin;
  bm174x_ioctl(fd,1,&item);
  return;
}

