
int LZ4_decompress_fast_usingDict
              (char *source,char *dest,int originalSize,char *dictStart,int dictSize)

{
  U16 UVar1;
  size_t sVar2;
  BYTE *pBVar3;
  int iVar4;
  char *dictStart_local;
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
  int local_18;
  int local_14;
  char *local_10;
  char *local_c;
  
  if ((dictSize == 0) || (dictStart + dictSize == dest)) {
    local_18 = dictSize;
    oend = (BYTE *)(dest + originalSize);
    prefixStart = (BYTE *)(dest + -dictSize);
    ip = (BYTE *)source;
    op = (BYTE *)dest;
    local_14 = originalSize;
    local_10 = dest;
    local_c = source;
    do {
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
      if (oend + -(int)op < ml) {
        return -1;
      }
      match = op + -offset;
      if ((uint)((int)op - (int)prefixStart) < offset) {
        return -1;
      }
      if ((uint)((int)op - (int)prefixStart) < offset) {
        dictEnd = (BYTE *)0x0;
        extml = (size_t)(prefixStart + (offset - (int)op));
        extMatch = (BYTE *)-extml;
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
    } while (4 < (uint)((int)oend - (int)op));
    iVar4 = -1;
  }
  else {
    iVar4 = LZ4_decompress_fast_extDict(source,dest,originalSize,dictStart,dictSize);
  }
  return iVar4;
}

