
/* WARNING: Unknown calling convention */

void set_job_start_address(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002d280;
  *(uint *)(*(int *)(DAT_0002d27c + 0x8d4) + 0x118) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002d284 != '\0' || (*DAT_0002d288 != '\0')) || (6 < *DAT_0002d28c)))) {
    snprintf(tmp42,0x800,DAT_0002d290,DAT_0002d294,value);
    _applog(7,tmp42,false);
  }
  get_job_start_address();
  return;
}

