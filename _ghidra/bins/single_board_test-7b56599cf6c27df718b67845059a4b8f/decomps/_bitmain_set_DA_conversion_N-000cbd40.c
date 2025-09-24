
int32_t _bitmain_set_DA_conversion_N(int32_t fd,uint8_t N)

{
  char tmp42 [2048];
  
  builtin_strncpy(tmp42,"set DA conversion N failed\n",0x1c);
  _applog(0,tmp42,false);
  return -0x7ffffd00;
}

