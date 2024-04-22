
/* WARNING: Unknown calling convention */

void set_job_length(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002dfe0;
  *(uint *)(*(int *)(DAT_0002dfdc + 0x8d4) + 0x11c) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002dfe4 != '\0' || (*DAT_0002dfe8 != '\0')) || (6 < *DAT_0002dfec)))) {
    snprintf(tmp42,0x800,DAT_0002dff0,DAT_0002dff4,value);
    _applog(7,tmp42,false);
  }
  get_job_id();
  return;
}

