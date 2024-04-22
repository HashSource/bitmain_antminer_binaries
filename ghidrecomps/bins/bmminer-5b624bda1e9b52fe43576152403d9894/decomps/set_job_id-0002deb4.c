
/* WARNING: Unknown calling convention */

void set_job_id(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002df08;
  *(uint *)(*(int *)(DAT_0002df04 + 0x8d4) + 0x124) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002df0c != '\0' || (*DAT_0002df10 != '\0')) || (6 < *DAT_0002df14)))) {
    snprintf(tmp42,0x800,DAT_0002df18,DAT_0002df1c,value);
    _applog(7,tmp42,false);
  }
  get_job_id();
  return;
}

