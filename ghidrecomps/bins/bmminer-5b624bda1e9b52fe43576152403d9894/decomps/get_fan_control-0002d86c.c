
/* WARNING: Unknown calling convention */

int get_fan_control(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002d8bc + 0x8d4) + 0x84);
  if ((*DAT_0002d8c0 != '\0') &&
     (((*DAT_0002d8c4 != '\0' || (*DAT_0002d8c8 != '\0')) || (6 < *DAT_0002d8cc)))) {
    snprintf(tmp42,0x800,DAT_0002d8d0,DAT_0002d8d4,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

