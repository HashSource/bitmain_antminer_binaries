
/* WARNING: Unknown calling convention */

uint get_pic_iic(void)

{
  uint uVar1;
  char tmp42 [2048];
  
  uVar1 = *(uint *)(*(int *)(DAT_0002bb80 + 0x8d4) + 0x30);
  if ((*DAT_0002bb84 != '\0') &&
     (((*DAT_0002bb88 != '\0' || (*DAT_0002bb8c != '\0')) || (6 < *DAT_0002bb90)))) {
    snprintf(tmp42,0x800,DAT_0002bb94,DAT_0002bb98,uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

