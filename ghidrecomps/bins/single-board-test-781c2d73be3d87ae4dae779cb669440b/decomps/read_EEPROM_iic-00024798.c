
/* WARNING: Unknown calling convention */

uchar read_EEPROM_iic(_Bool reg_addr_valid,uchar reg_addr,uchar which_iic,uchar which_chain)

{
  uchar uVar1;
  uint uVar2;
  
  uVar2 = (uint)reg_addr_valid;
  if (uVar2 != 0) {
    uVar2 = (uint)reg_addr << 8 | 0x1000000;
  }
  uVar1 = i2c_read(uVar2 | (uint)which_chain << 0x10 | 0xa00000 | (uint)which_iic << 0x1a);
  return uVar1;
}

