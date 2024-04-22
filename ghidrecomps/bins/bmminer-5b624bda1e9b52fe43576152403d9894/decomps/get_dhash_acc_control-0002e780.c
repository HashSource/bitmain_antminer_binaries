
/* WARNING: Unknown calling convention */

int get_dhash_acc_control(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002e7d0 + 0x8d4) + 0x100);
  if ((*DAT_0002e7d4 != '\0') &&
     (((*DAT_0002e7d8 != '\0' || (*DAT_0002e7dc != '\0')) || (6 < *DAT_0002e7e0)))) {
    snprintf(tmp42,0x800,DAT_0002e7e4,DAT_0002e7e8,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

