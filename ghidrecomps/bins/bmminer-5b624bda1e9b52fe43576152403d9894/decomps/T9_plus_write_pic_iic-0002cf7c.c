
/* WARNING: Unknown calling convention */

uchar T9_plus_write_pic_iic
                (_Bool read,_Bool reg_addr_valid,uchar reg_addr,uchar which_iic,uchar data)

{
  uchar uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)which_iic;
  uVar2 = axi_fpga_addr[0xc];
  while (-1 < (int)uVar2) {
    usleep(1000);
    uVar2 = axi_fpga_addr[0xc];
  }
  if (read) {
    uVar2 = 0x2000000;
  }
  else {
    uVar2 = 0;
  }
  if (reg_addr_valid) {
    uVar2 = uVar2 | (uint)reg_addr << 8 | 0x1000000;
  }
  if (fpga_version - 0xeU < 2) {
    uVar3 = uVar3 - 1 & 0xff;
  }
  uVar1 = set_iic(uVar2 | data | 0x400000 | (uVar3 & 3) << 0x1a);
  return uVar1;
}

