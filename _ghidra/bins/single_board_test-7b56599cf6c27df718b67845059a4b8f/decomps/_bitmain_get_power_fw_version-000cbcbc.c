
int32_t _bitmain_get_power_fw_version(int32_t fd)

{
  char tmp42 [2048];
  
  builtin_strncpy(tmp42,"get power version failed",0x18);
  tmp42[0x18] = '\n';
  tmp42[0x19] = '\0';
  _applog(0,tmp42,false);
  return -0x7ffffd00;
}

