
/* WARNING: Unknown calling convention */

int get_job_length(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002df70 + 0x8d4) + 0x11c);
  if ((*DAT_0002df74 != '\0') &&
     (((*DAT_0002df78 != '\0' || (*DAT_0002df7c != '\0')) || (6 < *DAT_0002df80)))) {
    snprintf(tmp42,0x800,DAT_0002df84,DAT_0002df88,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

