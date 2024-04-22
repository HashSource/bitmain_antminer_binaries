
uchar * ser_string(char *s,int *slen)

{
  size_t n;
  uchar *puVar1;
  uint __bsx_1;
  int *slen_local;
  char *s_local;
  uint *u32;
  ushort __bsx;
  uint16_t *u16;
  uchar *ret;
  size_t len;
  
  n = strlen(s);
  puVar1 = (uchar *)_cgmalloc(n + 9,"util.c","ser_string",0x3e4);
  if (n < 0xfd) {
    *puVar1 = (uchar)n;
    _cg_memcpy(puVar1 + 1,s,n,"util.c","ser_string",1000);
    *slen = n + 1;
  }
  else if (n < 0x10000) {
    *puVar1 = 0xfd;
    *(ushort *)(puVar1 + 1) = (ushort)((n & 0xff) << 8) | (ushort)n >> 8;
    _cg_memcpy(puVar1 + 3,s,n,"util.c","ser_string",0x3f1);
    *slen = n + 3;
  }
  else {
    *puVar1 = 0xfe;
    *(size_t *)(puVar1 + 1) = n >> 0x18 | (n & 0xff0000) >> 8 | (n & 0xff00) << 8 | n << 0x18;
    _cg_memcpy(puVar1 + 5,s,n,"util.c","ser_string",0x3fb);
    *slen = n + 5;
  }
  return puVar1;
}

