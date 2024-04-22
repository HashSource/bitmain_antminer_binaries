
/* WARNING: Unknown calling convention */

void address_to_pubkeyhash(uchar *pkh,char *addr)

{
  char *func;
  uchar b58bin [25];
  
  func = DAT_00015230;
  b58bin[0] = '\0';
  b58bin[1] = '\0';
  b58bin[2] = '\0';
  b58bin[3] = '\0';
  b58bin[4] = '\0';
  b58bin[5] = '\0';
  b58bin[6] = '\0';
  b58bin[7] = '\0';
  b58bin[8] = '\0';
  b58bin[9] = '\0';
  b58bin[10] = '\0';
  b58bin[11] = '\0';
  b58bin[12] = '\0';
  b58bin[13] = '\0';
  b58bin[14] = '\0';
  b58bin[15] = '\0';
  b58bin[16] = '\0';
  b58bin[17] = '\0';
  b58bin[18] = '\0';
  b58bin[19] = '\0';
  b58bin[20] = '\0';
  b58bin[21] = '\0';
  b58bin[22] = '\0';
  b58bin[23] = '\0';
  b58bin[24] = '\0';
  b58tobin(b58bin,addr);
  *pkh = 'v';
  pkh[1] = 0xa9;
  pkh[2] = '\x14';
  _cg_memcpy(pkh + 3,b58bin + 1,0x14,"util.c",func,0x3c6);
  pkh[0x17] = 0x88;
  pkh[0x18] = 0xac;
  return;
}

