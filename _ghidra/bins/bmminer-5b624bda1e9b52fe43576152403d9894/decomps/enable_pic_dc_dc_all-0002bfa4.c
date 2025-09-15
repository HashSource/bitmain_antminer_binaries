
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void enable_pic_dc_dc_all(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    while (dev->chain_exist[iVar1] == 1) {
      iVar2 = iVar1 + 1;
      enable_pic_dc_dc((uchar)iVar1);
      cgsleep_ms(1);
      iVar1 = iVar2;
      if (iVar2 == 0x10) {
        return;
      }
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x10);
  return;
}

