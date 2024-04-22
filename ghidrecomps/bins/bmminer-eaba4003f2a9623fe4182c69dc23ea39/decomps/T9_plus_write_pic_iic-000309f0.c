
uchar T9_plus_write_pic_iic
                (_Bool read,_Bool reg_addr_valid,uchar reg_addr,uchar which_iic,uchar data)

{
  uchar uVar1;
  uint uVar2;
  uchar which_iic_local;
  uchar reg_addr_local;
  _Bool reg_addr_valid_local;
  _Bool read_local;
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
  uVar1 = set_iic((uint)data | (which_iic & 7) << 0x10 | value | 0x400000);
  return uVar1;
}

