
/* WARNING: Unknown calling convention */

uchar * ser_string(char *s,int *slen)

{
  char *func;
  size_t n;
  size_t len;
  uchar *puVar1;
  uchar *ret;
  ushort __bsx;
  
  func = DAT_000151d4;
  n = strlen(s);
  puVar1 = (uchar *)_cgmalloc(n + 9,DAT_000151d8,func,0x3e4);
  if (n < 0xfd) {
    *puVar1 = (uchar)n;
    _cg_memcpy(puVar1 + 1,s,n,DAT_000151d8,func,1000);
    *slen = n + 1;
  }
  else if (n < 0x10000) {
    *puVar1 = 0xfd;
    *(ushort *)(puVar1 + 1) = (ushort)(byte)(n >> 8) | (ushort)(n << 8);
    _cg_memcpy(puVar1 + 3,s,n,DAT_000151d8,func,0x3f1);
    *slen = n + 3;
  }
  else {
    *puVar1 = 0xfe;
    *(size_t *)(puVar1 + 1) =
         n << 0x18 | (n >> 8 & 0xff) << 0x10 | (n >> 0x10 & 0xff) << 8 | n >> 0x18;
    _cg_memcpy(puVar1 + 5,s,n,DAT_000151d8,func,0x3fb);
    *slen = n + 5;
  }
  return puVar1;
}

