
uchar s11_write_vol_iic(_Bool read,_Bool reg_addr_valid,uchar reg_addr,uchar which_iic,
                       uchar which_chain,uchar data)

{
  uchar uVar1;
  uint uVar2;
  uchar which_iic_local;
  uchar reg_addr_local;
  _Bool reg_addr_valid_local;
  _Bool read_local;
  char tmp42 [2048];
  uint ret;
  uint counter;
  uint value;
  
  value = 0;
  while( true ) {
    uVar2 = get_iic();
    if ((int)uVar2 < 0) break;
    usleep(1000);
  }
  if (read) {
    value = 0x2000000;
  }
  if (reg_addr_valid) {
    value = (uint)reg_addr << 8 | value | 0x1000000;
  }
  if (which_iic == '\0') {
    value = value | 0x400000;
  }
  else if (which_iic == '\x01') {
    value = value | 0x200000;
  }
  uVar2 = (uint)data | (which_chain & 7) << 0x10 | (which_iic & 3) << 0x1a | value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"IIC[%d] write data: %x",(uint)which_iic,uVar2);
    _applog(7,tmp42,false);
  }
  uVar1 = set_iic(uVar2);
  return uVar1;
}

