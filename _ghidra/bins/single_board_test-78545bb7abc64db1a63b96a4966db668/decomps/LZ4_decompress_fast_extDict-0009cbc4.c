
int LZ4_decompress_fast_extDict
              (char *source,char *dest,int originalSize,void *dictStart,size_t dictSize)

{
  U16 UVar1;
  size_t sVar2;
  BYTE *pBVar3;
  void *dictStart_local;
  int originalSize_local;
  char *dest_local;
  char *source_local;
  BYTE *ip;
  size_t u;
  size_t extml;
  BYTE *extMatch;
  BYTE *dictEnd;
  BYTE *match;
  size_t offset;
  size_t ml;
  size_t ll;
  uint token;
  BYTE *prefixStart;
  BYTE *oend;
  BYTE *op;
  size_t local_20;
  void *local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  char *local_c;
  
  local_18 = 0;
  local_20 = dictSize;
  oend = (BYTE *)(dest + originalSize);
  ip = (BYTE *)source;
  prefixStart = (BYTE *)dest;
  op = (BYTE *)dest;
  local_1c = dictStart;
  local_14 = originalSize;
  local_10 = dest;
  local_c = source;
  while( true ) {
    pBVar3 = ip + 1;
    token = (uint)*ip;
    ll = (size_t)(*ip >> 4);
    ip = pBVar3;
    if (ll == 0xf) {
      sVar2 = read_long_length_no_check(&ip);
      ll = ll + sVar2;
    }
    if ((uint)((int)oend - (int)op) < ll) {
      return -1;
    }
    memmove(op,ip,ll);
    op = op + ll;
    ip = ip + ll;
    if ((uint)((int)oend - (int)op) < 0xc) {
      if (oend != op) {
        return -1;
      }
      return (int)ip - (int)local_c;
    }
    ml = token & 0xf;
    UVar1 = LZ4_readLE16(ip);
    offset = (size_t)UVar1;
    ip = ip + 2;
    if (ml == 0xf) {
      sVar2 = read_long_length_no_check(&ip);
      ml = ml + sVar2;
    }
    ml = ml + 4;
    if ((uint)((int)oend - (int)op) < ml) break;
    match = op + -offset;
    if (op + (local_20 - (int)prefixStart) < offset) {
      return -1;
    }
    if ((uint)((int)op - (int)prefixStart) < offset) {
      dictEnd = (BYTE *)(local_20 + (int)local_1c);
      extMatch = dictEnd + -(int)(prefixStart + (offset - (int)op));
      extml = (int)dictEnd - (int)extMatch;
      if (ml < extml) {
        memmove(op,extMatch,ml);
        op = op + ml;
        ml = 0;
      }
      else {
        memmove(op,extMatch,extml);
        op = op + extml;
        ml = ml - extml;
      }
      match = prefixStart;
    }
    for (u = 0; u < ml; u = u + 1) {
      op[u] = match[u];
    }
    op = op + ml;
    if ((uint)((int)oend - (int)op) < 5) {
      return -1;
    }
  }
  return -1;
}

