
void address_to_pubkeyhash(uchar *pkh,char *addr)

{
  char *addr_local;
  uchar *pkh_local;
  uchar b58bin [25];
  
  memset(b58bin,0,0x19);
  b58tobin(b58bin,addr);
  *pkh = 'v';
  pkh[1] = 0xa9;
  pkh[2] = '\x14';
  _cg_memcpy(pkh + 3,b58bin + 1,0x14,"util.c","address_to_pubkeyhash",0x3c6);
  pkh[0x17] = 0x88;
  pkh[0x18] = 0xac;
  return;
}

