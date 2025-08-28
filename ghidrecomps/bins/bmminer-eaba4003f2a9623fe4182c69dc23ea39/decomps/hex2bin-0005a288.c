
_Bool hex2bin(uchar *p,char *hexstr,size_t len)

{
  byte bVar1;
  byte *pbVar2;
  size_t len_local;
  char *hexstr_local;
  uchar *p_local;
  char tmp42 [2048];
  int nibble2;
  int nibble1;
  uchar idx;
  _Bool ret;
  
  ret = false;
  len_local = len;
  hexstr_local = hexstr;
  p_local = p;
  while( true ) {
    if ((*hexstr_local == '\0') || (len_local == 0)) {
      if ((len_local == 0) && (*hexstr_local == '\0')) {
        ret = true;
      }
      return ret;
    }
    if (hexstr_local[1] == '\0') {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        builtin_strncpy(tmp42,"hex2bin str truncate",0x14);
        tmp42[0x14] = 'd';
        tmp42[0x15] = '\0';
        _applog(3,tmp42,false);
      }
      return false;
    }
    bVar1 = *hexstr_local;
    pbVar2 = (byte *)(hexstr_local + 1);
    hexstr_local = hexstr_local + 2;
    if ((hex2bin_tbl[bVar1] < 0) || (hex2bin_tbl[*pbVar2] < 0)) break;
    *p_local = (byte)hex2bin_tbl[*pbVar2] | (byte)((hex2bin_tbl[bVar1] & 0xfU) << 4);
    p_local = p_local + 1;
    len_local = len_local - 1;
  }
  if ((use_syslog != false) || ((opt_log_output != false || (2 < opt_log_level)))) {
    builtin_strncpy(tmp42,"hex2bin scan failed",0x14);
    _applog(3,tmp42,false);
  }
  return false;
}

