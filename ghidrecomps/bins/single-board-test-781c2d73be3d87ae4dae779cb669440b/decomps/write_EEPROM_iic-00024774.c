
/* WARNING: Unknown calling convention */

void write_EEPROM_iic(_Bool reg_addr_valid,uchar reg_addr,uchar which_iic,uchar which_chain,
                     uchar data)

{
  uint uVar1;
  
  uVar1 = (uint)reg_addr_valid;
  if (uVar1 != 0) {
    uVar1 = (uint)reg_addr << 8 | 0x1000000;
  }
  i2c_write(uVar1 | data | 0xa00000 | (uint)which_chain << 0x10 | (uint)which_iic << 0x1a);
  return;
}

