
uchar write_pic_iic(_Bool read,_Bool reg_addr_valid,uchar reg_addr,uchar chain,uchar data)

{
  uchar uVar1;
  uchar chain_local;
  uchar reg_addr_local;
  _Bool reg_addr_valid_local;
  _Bool read_local;
  uchar ret;
  uint value;
  
  value = 0;
  if (read) {
    value = 0x2000000;
  }
  if (reg_addr_valid) {
    value = (uint)reg_addr << 8 | value | 0x1000000;
  }
  uVar1 = set_pic_iic((uint)data | (chain & 0xf) << 0x10 | value | 0x400000);
  return uVar1;
}

