
int32_t _bitmain_set_watchdog(int32_t fd,uint8_t ctrl)

{
  char tmp42 [2048];
  
  builtin_strncpy(tmp42,"set watchdog failed\n",0x14);
  tmp42[0x14] = '\0';
  _applog(0,tmp42,false);
  return -0x7ffffd00;
}

