
/* WARNING: Unknown calling convention */

void address_to_pubkeyhash(uchar *pkh,char *addr)

{
  uchar b58bin [25];
  
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
  b58bin[0xb] = '\0';
  b58bin[0xc] = '\0';
  b58bin[0xd] = '\0';
  b58bin[0xe] = '\0';
  b58bin[0xf] = '\0';
  b58bin[0x10] = '\0';
  b58bin[0x11] = '\0';
  b58bin[0x12] = '\0';
  b58bin[0x13] = '\0';
  b58bin[0x14] = '\0';
  b58bin[0x15] = '\0';
  b58bin[0x16] = '\0';
  b58bin[0x17] = '\0';
  b58bin[0x18] = '\0';
  b58tobin(b58bin,addr);
  *pkh = 'v';
  pkh[1] = 0xa9;
  pkh[2] = '\x14';
  _cg_memcpy(pkh + 3,b58bin + 1,0x14,"util.c","address_to_pubkeyhash",0x3c6);
  pkh[0x17] = 0x88;
  pkh[0x18] = 0xac;
  return;
}

