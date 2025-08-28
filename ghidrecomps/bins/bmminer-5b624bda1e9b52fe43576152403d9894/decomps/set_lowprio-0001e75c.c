
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_lowprio(void)

{
  char tmp42 [2048];
  
  builtin_strncpy(tmp42,"Unable to set thread to low priority",0x24);
  tmp42[0x24] = '\0';
  _applog(6,tmp42,false);
  return;
}

