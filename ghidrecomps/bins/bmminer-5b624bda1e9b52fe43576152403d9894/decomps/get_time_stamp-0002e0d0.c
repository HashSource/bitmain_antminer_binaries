
/* WARNING: Unknown calling convention */

int get_time_stamp(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002e120 + 0x8d4) + 0x134);
  if ((*DAT_0002e124 != '\0') &&
     (((*DAT_0002e128 != '\0' || (*DAT_0002e12c != '\0')) || (6 < *DAT_0002e130)))) {
    snprintf(tmp42,0x800,DAT_0002e134,DAT_0002e138,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

