
uint8_t hex2val(char *base,size_t off)

{
  byte bVar1;
  uint8_t uVar2;
  size_t off_local;
  char *base_local;
  char tmp42 [1024];
  char c;
  
  bVar1 = base[off];
  if ((bVar1 < 0x30) || (0x39 < bVar1)) {
    if ((bVar1 < 0x61) || (0x66 < bVar1)) {
      if ((bVar1 < 0x41) || (0x46 < bVar1)) {
        if ((use_syslog) || ((opt_log_output || (-1 < opt_log_level)))) {
          snprintf(tmp42,0x400,"Invalid hex char at offset %zd: ...%c...\n",off,(uint)bVar1);
          _applog(0,tmp42,false);
        }
        uVar2 = '\0';
      }
      else {
        uVar2 = bVar1 - 0x37;
      }
    }
    else {
      uVar2 = bVar1 + 0xa9;
    }
  }
  else {
    uVar2 = bVar1 - 0x30;
  }
  return uVar2;
}

