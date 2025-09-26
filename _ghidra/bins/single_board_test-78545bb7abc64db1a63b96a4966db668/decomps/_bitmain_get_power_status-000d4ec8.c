
int32_t _bitmain_get_power_status(int32_t fd)

{
  char tmp42 [2048];
  
  builtin_strncpy(tmp42,"get power status failed\n",0x18);
  tmp42[0x18] = '\0';
  _applog(0,tmp42,false);
  return -0x7ffffd00;
}

