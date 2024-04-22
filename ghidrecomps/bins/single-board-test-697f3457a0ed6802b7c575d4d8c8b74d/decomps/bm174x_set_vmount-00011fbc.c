
void bm174x_set_vmount(int fd,int vmount)

{
  int vmount_local;
  int fd_local;
  base_type_t item;
  bm174x_reg vmount_reg;
  
  vmount_reg.core_timeout.core_timeout._0_1_ = (undefined)reg_value.analog_mux_control;
  vmount_reg.core_timeout.core_timeout._1_3_ = (undefined3)(reg_value.analog_mux_control >> 8);
  vmount_reg.core_timeout.core_timeout._0_1_ =
       vmount_reg.core_timeout.core_timeout._0_1_ & 0xf8 | (byte)vmount & 7;
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '@';
  item.data = vmount_reg.reg_bin;
  reg_value.analog_mux_control = vmount_reg.reg_bin;
  bm174x_ioctl(fd,1,&item);
  return;
}

