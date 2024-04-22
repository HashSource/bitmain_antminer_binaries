
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
        tmp42[0] = s_hex2bin_str_truncated_0007ada4[0];
        tmp42[1] = s_hex2bin_str_truncated_0007ada4[1];
        tmp42[2] = s_hex2bin_str_truncated_0007ada4[2];
        tmp42[3] = s_hex2bin_str_truncated_0007ada4[3];
        tmp42[4] = s_hex2bin_str_truncated_0007ada4[4];
        tmp42[5] = s_hex2bin_str_truncated_0007ada4[5];
        tmp42[6] = s_hex2bin_str_truncated_0007ada4[6];
        tmp42[7] = s_hex2bin_str_truncated_0007ada4[7];
        tmp42[8] = s_hex2bin_str_truncated_0007ada4[8];
        tmp42[9] = s_hex2bin_str_truncated_0007ada4[9];
        tmp42[10] = s_hex2bin_str_truncated_0007ada4[10];
        tmp42[11] = s_hex2bin_str_truncated_0007ada4[11];
        tmp42[12] = s_hex2bin_str_truncated_0007ada4[12];
        tmp42[13] = s_hex2bin_str_truncated_0007ada4[13];
        tmp42[14] = s_hex2bin_str_truncated_0007ada4[14];
        tmp42[15] = s_hex2bin_str_truncated_0007ada4[15];
        tmp42[16] = s_hex2bin_str_truncated_0007ada4[16];
        tmp42[17] = s_hex2bin_str_truncated_0007ada4[17];
        tmp42[18] = s_hex2bin_str_truncated_0007ada4[18];
        tmp42[19] = s_hex2bin_str_truncated_0007ada4[19];
        tmp42._20_2_ = (undefined2)ram0x0007adb8;
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
    tmp42[0] = s_hex2bin_scan_failed_0007adbc[0];
    tmp42[1] = s_hex2bin_scan_failed_0007adbc[1];
    tmp42[2] = s_hex2bin_scan_failed_0007adbc[2];
    tmp42[3] = s_hex2bin_scan_failed_0007adbc[3];
    tmp42[4] = s_hex2bin_scan_failed_0007adbc[4];
    tmp42[5] = s_hex2bin_scan_failed_0007adbc[5];
    tmp42[6] = s_hex2bin_scan_failed_0007adbc[6];
    tmp42[7] = s_hex2bin_scan_failed_0007adbc[7];
    tmp42[8] = s_hex2bin_scan_failed_0007adbc[8];
    tmp42[9] = s_hex2bin_scan_failed_0007adbc[9];
    tmp42[10] = s_hex2bin_scan_failed_0007adbc[10];
    tmp42[11] = s_hex2bin_scan_failed_0007adbc[11];
    tmp42[12] = s_hex2bin_scan_failed_0007adbc[12];
    tmp42[13] = s_hex2bin_scan_failed_0007adbc[13];
    tmp42[14] = s_hex2bin_scan_failed_0007adbc[14];
    tmp42[15] = s_hex2bin_scan_failed_0007adbc[15];
    tmp42[16] = s_hex2bin_scan_failed_0007adbc[16];
    tmp42[17] = s_hex2bin_scan_failed_0007adbc[17];
    tmp42[18] = s_hex2bin_scan_failed_0007adbc[18];
    tmp42[19] = s_hex2bin_scan_failed_0007adbc[19];
    _applog(3,tmp42,false);
  }
  return false;
}

