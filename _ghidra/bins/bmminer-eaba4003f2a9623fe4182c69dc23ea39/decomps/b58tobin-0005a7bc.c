
void b58tobin(uchar *b58bin,char *b58)

{
  longlong lVar1;
  size_t sVar2;
  uint __bsx;
  uint uVar3;
  char *b58_local;
  uchar *b58bin_local;
  uint bin32 [7];
  uint64_t t;
  int len;
  int j;
  int i;
  uint c;
  
  memset(bin32,0,0x1c);
  sVar2 = strlen(b58);
  for (i = 0; i < (int)sVar2; i = i + 1) {
    c = b58tobin_tbl[(byte)b58[i]];
    for (j = 6; -1 < j; j = j + -1) {
      lVar1 = (ulonglong)bin32[j] * 0x3a + (ulonglong)c;
      t._4_4_ = (uint)((ulonglong)lVar1 >> 0x20);
      c = t._4_4_ & 0x3f;
      t._0_4_ = (uint)lVar1;
      bin32[j] = (uint)t;
    }
  }
  *b58bin = (uchar)bin32[0];
  b58bin_local = b58bin + 1;
  for (i = 1; i < 7; i = i + 1) {
    uVar3 = bin32[i];
    *(uint *)b58bin_local =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    b58bin_local = b58bin_local + 4;
  }
  return;
}

