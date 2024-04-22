
/* WARNING: Unknown calling convention */

uchar T9_plus_write_pic_iic
                (_Bool read,_Bool reg_addr_valid,uchar reg_addr,uchar which_iic,uchar data)

{
  int iVar1;
  uchar uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = DAT_0002cfec;
  uVar5 = (uint)which_iic;
  iVar3 = *(int *)(*(int *)(DAT_0002cfec + 0x8d4) + 0x30);
  while (-1 < iVar3) {
    usleep(1000);
    iVar3 = *(int *)(*(int *)(iVar1 + 0x8d4) + 0x30);
  }
  if (read) {
    uVar4 = 0x2000000;
  }
  else {
    uVar4 = 0;
  }
  if (reg_addr_valid) {
    uVar4 = uVar4 | (uint)reg_addr << 8 | 0x1000000;
  }
  if (*DAT_0002cff0 - 0xeU < 2) {
    uVar5 = uVar5 - 1 & 0xff;
  }
  uVar2 = set_iic(uVar4 | data | 0x400000 | (uVar5 & 3) << 0x1a);
  return uVar2;
}

