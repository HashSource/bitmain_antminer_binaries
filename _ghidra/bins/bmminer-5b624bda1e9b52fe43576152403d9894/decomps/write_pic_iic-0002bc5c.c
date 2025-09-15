
/* WARNING: Unknown calling convention */

uchar write_pic_iic(_Bool read,_Bool reg_addr_valid,uchar reg_addr,uchar chain,uchar data)

{
  uchar uVar1;
  uint uVar2;
  
  if (read) {
    uVar2 = 0x2000000;
  }
  else {
    uVar2 = 0;
  }
  if (reg_addr_valid) {
    uVar2 = uVar2 | (uint)reg_addr << 8 | 0x1000000;
  }
  uVar1 = set_pic_iic(uVar2 | data | 0x400000 | (chain & 0xf) << 0x10);
  return uVar1;
}

