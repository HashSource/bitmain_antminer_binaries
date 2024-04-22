
/* WARNING: Unknown calling convention */

int get_job_start_address(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002d210 + 0x8d4) + 0x118);
  if ((*DAT_0002d214 != '\0') &&
     (((*DAT_0002d218 != '\0' || (*DAT_0002d21c != '\0')) || (6 < *DAT_0002d220)))) {
    snprintf(tmp42,0x800,DAT_0002d224,DAT_0002d228,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

