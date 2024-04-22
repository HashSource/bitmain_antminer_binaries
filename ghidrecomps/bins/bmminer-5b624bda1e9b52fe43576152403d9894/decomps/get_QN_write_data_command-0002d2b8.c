
/* WARNING: Unknown calling convention */

int get_QN_write_data_command(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002d308 + 0x8d4) + 0x80);
  if ((*DAT_0002d30c != '\0') &&
     (((*DAT_0002d310 != '\0' || (*DAT_0002d314 != '\0')) || (6 < *DAT_0002d318)))) {
    snprintf(tmp42,0x800,DAT_0002d31c,DAT_0002d320,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

