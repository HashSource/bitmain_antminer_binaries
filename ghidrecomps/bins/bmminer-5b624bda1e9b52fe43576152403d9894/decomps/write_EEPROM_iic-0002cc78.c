
/* WARNING: Unknown calling convention */

uchar write_EEPROM_iic(_Bool read,_Bool reg_addr_valid,uchar reg_addr,uchar which_iic,uchar data)

{
  uchar uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)which_iic;
  if (read) {
    uVar2 = 0x2000000;
  }
  else {
    uVar2 = 0;
  }
  usleep(1000);
  usleep(1000);
  usleep(1000);
  usleep(1000);
  if (reg_addr_valid) {
    uVar2 = uVar2 | (uint)reg_addr << 8 | 0x1000000;
  }
  if (*DAT_0002cce4 - 0xeU < 2) {
    uVar3 = uVar3 - 1 & 0xff;
  }
  uVar1 = set_iic(uVar2 | data | 0xa00000 | (uVar3 & 3) << 0x1a);
  return uVar1;
}

