
/* WARNING: Unknown calling convention */

void enable_pic_dc_dc_all(void)

{
  uchar chain;
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0002bfd4;
  iVar2 = 0;
  do {
    while (*(int *)(*piVar1 + (iVar2 + 2) * 4) == 1) {
      chain = (uchar)iVar2;
      iVar2 = iVar2 + 1;
      enable_pic_dc_dc(chain);
      cgsleep_ms(1);
      if (iVar2 == 0x10) {
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x10);
  return;
}

