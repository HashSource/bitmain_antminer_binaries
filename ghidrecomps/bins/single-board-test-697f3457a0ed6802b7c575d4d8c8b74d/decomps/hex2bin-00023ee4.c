
int hex2bin(uchar *p,char *hexstr,size_t len)

{
  byte bVar1;
  byte *pbVar2;
  size_t len_local;
  char *hexstr_local;
  uchar *p_local;
  int nibble2;
  int nibble1;
  uchar idx;
  int ret;
  
  ret = 0;
  len_local = len;
  hexstr_local = hexstr;
  p_local = p;
  while( true ) {
    if ((*hexstr_local == '\0') || (len_local == 0)) {
      if ((len_local == 0) && (*hexstr_local == '\0')) {
        ret = 1;
      }
      return ret;
    }
    if (hexstr_local[1] == '\0') {
      return 0;
    }
    pbVar2 = (byte *)(hexstr_local + 1);
    bVar1 = *hexstr_local;
    hexstr_local = hexstr_local + 2;
    if ((hex2bin_tbl[bVar1] < 0) || (hex2bin_tbl[*pbVar2] < 0)) break;
    *p_local = (byte)hex2bin_tbl[*pbVar2] | (byte)((hex2bin_tbl[bVar1] & 0xffU) << 4);
    len_local = len_local - 1;
    p_local = p_local + 1;
  }
  return 0;
}

