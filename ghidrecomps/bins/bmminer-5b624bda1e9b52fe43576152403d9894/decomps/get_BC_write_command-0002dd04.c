
/* WARNING: Unknown calling convention */

int get_BC_write_command(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002dd54 + 0x8d4) + 0xc0);
  if ((*DAT_0002dd58 != '\0') &&
     (((*DAT_0002dd5c != '\0' || (*DAT_0002dd60 != '\0')) || (6 < *DAT_0002dd64)))) {
    snprintf(tmp42,0x800,DAT_0002dd68,DAT_0002dd6c,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

