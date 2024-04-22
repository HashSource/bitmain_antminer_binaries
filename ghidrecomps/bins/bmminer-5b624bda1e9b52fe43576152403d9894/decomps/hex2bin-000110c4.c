
/* WARNING: Unknown calling convention */

_Bool hex2bin(uchar *p,char *hexstr,size_t len)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  char cVar4;
  uchar *idx;
  char *pcVar5;
  uint uVar6;
  int nibble1;
  uint uVar7;
  int nibble2;
  char tmp42 [2048];
  
  iVar3 = DAT_0001118c;
  if ((byte)*hexstr == 0) {
LAB_0001111a:
    cVar4 = '\x01' - (char)len;
    if (1 < len) {
      cVar4 = '\0';
    }
  }
  else {
    if (len != 0) {
      if ((byte)hexstr[1] == 0) {
LAB_00011124:
        if (((*DAT_00011190 != '\0') || (*DAT_00011194 != '\0')) || (2 < *DAT_00011198)) {
          tmp42._0_4_ = *DAT_0001119c;
          tmp42._4_4_ = DAT_0001119c[1];
          tmp42._8_4_ = DAT_0001119c[2];
          tmp42._12_4_ = DAT_0001119c[3];
          tmp42._16_4_ = DAT_0001119c[4];
          tmp42._20_2_ = (undefined2)DAT_0001119c[5];
          _applog(3,tmp42,false);
        }
      }
      else {
        uVar6 = *(uint *)(DAT_0001118c + (uint)(byte)*hexstr * 4);
        uVar7 = *(uint *)(DAT_0001118c + (uint)(byte)hexstr[1] * 4);
        if (-1 < (int)(uVar7 | uVar6)) {
          pcVar5 = hexstr + 4;
          do {
            len = len - 1;
            *p = (byte)uVar7 | (byte)((uVar6 & 0xff) << 4);
            pbVar2 = (byte *)(pcVar5 + -2);
            if (*pbVar2 == 0) goto LAB_0001111a;
            if (len == 0) goto LAB_00011154;
            pbVar1 = (byte *)(pcVar5 + -1);
            pcVar5 = pcVar5 + 2;
            if (*pbVar1 == 0) goto LAB_00011124;
            uVar6 = *(uint *)(iVar3 + (uint)*pbVar2 * 4);
            uVar7 = *(uint *)(iVar3 + (uint)*pbVar1 * 4);
            p = p + 1;
          } while (-1 < (int)(uVar7 | uVar6));
        }
        if (((*DAT_00011190 != '\0') || (*DAT_00011194 != '\0')) || (2 < *DAT_00011198)) {
          tmp42._0_4_ = *DAT_000111a0;
          tmp42._4_4_ = DAT_000111a0[1];
          tmp42._8_4_ = DAT_000111a0[2];
          tmp42._12_4_ = DAT_000111a0[3];
          tmp42._16_4_ = DAT_000111a0[4];
          _applog(3,tmp42,false);
          return false;
        }
      }
    }
LAB_00011154:
    cVar4 = '\0';
  }
  return (_Bool)cVar4;
}

