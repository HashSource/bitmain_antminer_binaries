
/* WARNING: Unknown calling convention */

int get_job_id(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002de98 + 0x8d4) + 0x124);
  if ((*DAT_0002de9c != '\0') &&
     (((*DAT_0002dea0 != '\0' || (*DAT_0002dea4 != '\0')) || (6 < *DAT_0002dea8)))) {
    snprintf(tmp42,0x800,DAT_0002deac,DAT_0002deb0,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

