
/* WARNING: Unknown calling convention */

pool * priority_pool(int choice)

{
  char tmp42 [2048];
  
  if (((*DAT_0000a8e4 != '\0') || (*DAT_0000a8e8 != '\0')) || (2 < *DAT_0000a8ec)) {
    snprintf(tmp42,0x800,DAT_0000a8f0,choice);
    _applog(3,tmp42,false);
  }
  return *(pool **)(*DAT_0000a8f4 + choice * 4);
}

