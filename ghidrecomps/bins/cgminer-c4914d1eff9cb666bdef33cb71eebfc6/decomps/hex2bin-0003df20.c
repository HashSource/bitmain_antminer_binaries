
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
        tmp42[0] = s_hex2bin_str_truncated_00087a18[0];
        tmp42[1] = s_hex2bin_str_truncated_00087a18[1];
        tmp42[2] = s_hex2bin_str_truncated_00087a18[2];
        tmp42[3] = s_hex2bin_str_truncated_00087a18[3];
        tmp42[4] = s_hex2bin_str_truncated_00087a18[4];
        tmp42[5] = s_hex2bin_str_truncated_00087a18[5];
        tmp42[6] = s_hex2bin_str_truncated_00087a18[6];
        tmp42[7] = s_hex2bin_str_truncated_00087a18[7];
        tmp42[8] = s_hex2bin_str_truncated_00087a18[8];
        tmp42[9] = s_hex2bin_str_truncated_00087a18[9];
        tmp42[10] = s_hex2bin_str_truncated_00087a18[10];
        tmp42[11] = s_hex2bin_str_truncated_00087a18[11];
        tmp42[12] = s_hex2bin_str_truncated_00087a18[12];
        tmp42[13] = s_hex2bin_str_truncated_00087a18[13];
        tmp42[14] = s_hex2bin_str_truncated_00087a18[14];
        tmp42[15] = s_hex2bin_str_truncated_00087a18[15];
        tmp42[16] = s_hex2bin_str_truncated_00087a18[16];
        tmp42[17] = s_hex2bin_str_truncated_00087a18[17];
        tmp42[18] = s_hex2bin_str_truncated_00087a18[18];
        tmp42[19] = s_hex2bin_str_truncated_00087a18[19];
        tmp42._20_2_ = (undefined2)ram0x00087a2c;
        _applog(3,tmp42,false);
      }
      return false;
    }
    pbVar2 = (byte *)(hexstr_local + 1);
    bVar1 = *hexstr_local;
    hexstr_local = hexstr_local + 2;
    if ((hex2bin_tbl[bVar1] < 0) || (hex2bin_tbl[*pbVar2] < 0)) break;
    *p_local = (byte)hex2bin_tbl[*pbVar2] | (byte)((hex2bin_tbl[bVar1] & 0xffU) << 4);
    len_local = len_local - 1;
    p_local = p_local + 1;
  }
  if ((use_syslog != false) || ((opt_log_output != false || (2 < opt_log_level)))) {
    tmp42[0] = s_hex2bin_scan_failed_00087a30[0];
    tmp42[1] = s_hex2bin_scan_failed_00087a30[1];
    tmp42[2] = s_hex2bin_scan_failed_00087a30[2];
    tmp42[3] = s_hex2bin_scan_failed_00087a30[3];
    tmp42[4] = s_hex2bin_scan_failed_00087a30[4];
    tmp42[5] = s_hex2bin_scan_failed_00087a30[5];
    tmp42[6] = s_hex2bin_scan_failed_00087a30[6];
    tmp42[7] = s_hex2bin_scan_failed_00087a30[7];
    tmp42[8] = s_hex2bin_scan_failed_00087a30[8];
    tmp42[9] = s_hex2bin_scan_failed_00087a30[9];
    tmp42[10] = s_hex2bin_scan_failed_00087a30[10];
    tmp42[11] = s_hex2bin_scan_failed_00087a30[11];
    tmp42[12] = s_hex2bin_scan_failed_00087a30[12];
    tmp42[13] = s_hex2bin_scan_failed_00087a30[13];
    tmp42[14] = s_hex2bin_scan_failed_00087a30[14];
    tmp42[15] = s_hex2bin_scan_failed_00087a30[15];
    tmp42[16] = s_hex2bin_scan_failed_00087a30[16];
    tmp42[17] = s_hex2bin_scan_failed_00087a30[17];
    tmp42[18] = s_hex2bin_scan_failed_00087a30[18];
    tmp42[19] = s_hex2bin_scan_failed_00087a30[19];
    _applog(3,tmp42,false);
  }
  return false;
}

