
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
        tmp42[0] = s_hex2bin_str_truncated_0009eff0[0];
        tmp42[1] = s_hex2bin_str_truncated_0009eff0[1];
        tmp42[2] = s_hex2bin_str_truncated_0009eff0[2];
        tmp42[3] = s_hex2bin_str_truncated_0009eff0[3];
        tmp42[4] = s_hex2bin_str_truncated_0009eff0[4];
        tmp42[5] = s_hex2bin_str_truncated_0009eff0[5];
        tmp42[6] = s_hex2bin_str_truncated_0009eff0[6];
        tmp42[7] = s_hex2bin_str_truncated_0009eff0[7];
        tmp42[8] = s_hex2bin_str_truncated_0009eff0[8];
        tmp42[9] = s_hex2bin_str_truncated_0009eff0[9];
        tmp42[10] = s_hex2bin_str_truncated_0009eff0[10];
        tmp42[11] = s_hex2bin_str_truncated_0009eff0[11];
        tmp42[12] = s_hex2bin_str_truncated_0009eff0[12];
        tmp42[13] = s_hex2bin_str_truncated_0009eff0[13];
        tmp42[14] = s_hex2bin_str_truncated_0009eff0[14];
        tmp42[15] = s_hex2bin_str_truncated_0009eff0[15];
        tmp42[16] = s_hex2bin_str_truncated_0009eff0[16];
        tmp42[17] = s_hex2bin_str_truncated_0009eff0[17];
        tmp42[18] = s_hex2bin_str_truncated_0009eff0[18];
        tmp42[19] = s_hex2bin_str_truncated_0009eff0[19];
        tmp42._20_2_ = (undefined2)ram0x0009f004;
        _applog(3,tmp42,false);
      }
      return false;
    }
    pbVar2 = (byte *)(hexstr_local + 1);
    bVar1 = *hexstr_local;
    hexstr_local = hexstr_local + 2;
    if ((hex2bin_tbl[bVar1] < 0) || (hex2bin_tbl[*pbVar2] < 0)) break;
    *p_local = (byte)((hex2bin_tbl[bVar1] & 0xffU) << 4) | (byte)hex2bin_tbl[*pbVar2];
    len_local = len_local - 1;
    p_local = p_local + 1;
  }
  if ((use_syslog != false) || ((opt_log_output != false || (2 < opt_log_level)))) {
    tmp42[0] = s_hex2bin_scan_failed_0009f008[0];
    tmp42[1] = s_hex2bin_scan_failed_0009f008[1];
    tmp42[2] = s_hex2bin_scan_failed_0009f008[2];
    tmp42[3] = s_hex2bin_scan_failed_0009f008[3];
    tmp42[4] = s_hex2bin_scan_failed_0009f008[4];
    tmp42[5] = s_hex2bin_scan_failed_0009f008[5];
    tmp42[6] = s_hex2bin_scan_failed_0009f008[6];
    tmp42[7] = s_hex2bin_scan_failed_0009f008[7];
    tmp42[8] = s_hex2bin_scan_failed_0009f008[8];
    tmp42[9] = s_hex2bin_scan_failed_0009f008[9];
    tmp42[10] = s_hex2bin_scan_failed_0009f008[10];
    tmp42[11] = s_hex2bin_scan_failed_0009f008[11];
    tmp42[12] = s_hex2bin_scan_failed_0009f008[12];
    tmp42[13] = s_hex2bin_scan_failed_0009f008[13];
    tmp42[14] = s_hex2bin_scan_failed_0009f008[14];
    tmp42[15] = s_hex2bin_scan_failed_0009f008[15];
    tmp42[16] = s_hex2bin_scan_failed_0009f008[16];
    tmp42[17] = s_hex2bin_scan_failed_0009f008[17];
    tmp42[18] = s_hex2bin_scan_failed_0009f008[18];
    tmp42[19] = s_hex2bin_scan_failed_0009f008[19];
    _applog(3,tmp42,false);
  }
  return false;
}

