
/* WARNING: Unknown calling convention */

_Bool hex2bin(uchar *p,char *hexstr,size_t len)

{
  byte *pbVar1;
  byte *pbVar2;
  char cVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char tmp42 [2048];
  
  if ((byte)*hexstr == 0) {
LAB_0001111a:
    cVar3 = '\x01' - (char)len;
    if (1 < len) {
      cVar3 = '\0';
    }
  }
  else {
    if (len != 0) {
      if ((byte)hexstr[1] == 0) {
LAB_00011124:
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          builtin_strncpy(tmp42,"hex2bin str truncate",0x14);
          tmp42[0x14] = 'd';
          tmp42[0x15] = '\0';
          _applog(3,tmp42,false);
        }
      }
      else {
        uVar5 = hex2bin_tbl[(byte)*hexstr];
        uVar6 = hex2bin_tbl[(byte)hexstr[1]];
        if (-1 < (int)(uVar6 | uVar5)) {
          pcVar4 = hexstr + 4;
          do {
            len = len - 1;
            *p = (byte)uVar6 | (byte)((uVar5 & 0xff) << 4);
            pbVar2 = (byte *)(pcVar4 + -2);
            if (*pbVar2 == 0) goto LAB_0001111a;
            if (len == 0) goto LAB_00011154;
            pbVar1 = (byte *)(pcVar4 + -1);
            pcVar4 = pcVar4 + 2;
            if (*pbVar1 == 0) goto LAB_00011124;
            uVar5 = hex2bin_tbl[*pbVar2];
            uVar6 = hex2bin_tbl[*pbVar1];
            p = p + 1;
          } while (-1 < (int)(uVar6 | uVar5));
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          builtin_strncpy(tmp42,"hex2bin scan failed",0x14);
          _applog(3,tmp42,false);
          return false;
        }
      }
    }
LAB_00011154:
    cVar3 = '\0';
  }
  return (_Bool)cVar3;
}

