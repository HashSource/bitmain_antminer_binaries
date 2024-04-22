
/* WARNING: Unknown calling convention */

int get_hardware_version(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = **(int **)(DAT_0002da0c + 0x8d4);
  if ((*DAT_0002da10 != '\0') &&
     (((*DAT_0002da14 != '\0' || (*DAT_0002da18 != '\0')) || (6 < *DAT_0002da1c)))) {
    snprintf(tmp42,0x800,DAT_0002da20,DAT_0002da24,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

