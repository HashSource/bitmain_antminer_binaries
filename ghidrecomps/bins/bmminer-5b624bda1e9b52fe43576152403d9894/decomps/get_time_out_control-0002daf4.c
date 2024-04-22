
/* WARNING: Unknown calling convention */

int get_time_out_control(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002db44 + 0x8d4) + 0x88);
  if ((*DAT_0002db48 != '\0') &&
     (((*DAT_0002db4c != '\0' || (*DAT_0002db50 != '\0')) || (6 < *DAT_0002db54)))) {
    snprintf(tmp42,0x800,DAT_0002db58,DAT_0002db5c,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

