
int LZ4_decompress_fast_continue
              (LZ4_streamDecode_t *LZ4_streamDecode,char *source,char *dest,int originalSize)

{
  U16 UVar1;
  int iVar2;
  size_t sVar3;
  BYTE *pBVar4;
  int originalSize_local;
  char *dest_local;
  char *source_local;
  LZ4_streamDecode_t *LZ4_streamDecode_local;
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
  size_t local_28;
  LZ4_byte *local_24;
  size_t local_20;
  int local_1c;
  char *local_18;
  char *local_14;
  LZ4_streamDecode_t_internal *lz4sd;
  int result;
  
  lz4sd = (LZ4_streamDecode_t_internal *)LZ4_streamDecode;
  if ((LZ4_streamDecode->internal_donotuse).prefixSize == 0) {
    iVar2 = LZ4_decompress_fast(source,dest,originalSize);
    if (0 < iVar2) {
      lz4sd->prefixSize = originalSize;
      lz4sd->prefixEnd = (LZ4_byte *)(dest + originalSize);
    }
  }
  else if ((LZ4_streamDecode->internal_donotuse).prefixEnd == (LZ4_byte *)dest) {
    local_20 = (LZ4_streamDecode->internal_donotuse).prefixSize;
    local_24 = (LZ4_streamDecode->internal_donotuse).externalDict;
    local_28 = (LZ4_streamDecode->internal_donotuse).extDictSize;
    oend = (BYTE *)(dest + originalSize);
    prefixStart = (BYTE *)(dest + -local_20);
    ip = (BYTE *)source;
    op = (BYTE *)dest;
    local_1c = originalSize;
    local_18 = dest;
    local_14 = source;
    do {
      pBVar4 = ip + 1;
      token = (uint)*ip;
      ll = (size_t)(*ip >> 4);
      ip = pBVar4;
      if (ll == 0xf) {
        sVar3 = read_long_length_no_check(&ip);
        ll = ll + sVar3;
      }
      if ((uint)((int)oend - (int)op) < ll) {
        iVar2 = -1;
        goto LAB_000d1b92;
      }
      memmove(op,ip,ll);
      op = op + ll;
      ip = ip + ll;
      if ((uint)((int)oend - (int)op) < 0xc) {
        if (oend == op) {
          iVar2 = (int)ip - (int)local_14;
        }
        else {
          iVar2 = -1;
        }
        goto LAB_000d1b92;
      }
      ml = token & 0xf;
      UVar1 = LZ4_readLE16(ip);
      offset = (size_t)UVar1;
      ip = ip + 2;
      if (ml == 0xf) {
        sVar3 = read_long_length_no_check(&ip);
        ml = ml + sVar3;
      }
      ml = ml + 4;
      if ((uint)((int)oend - (int)op) < ml) {
        iVar2 = -1;
        goto LAB_000d1b92;
      }
      match = op + -offset;
      if (op + (local_28 - (int)prefixStart) < offset) {
        iVar2 = -1;
        goto LAB_000d1b92;
      }
      if ((uint)((int)op - (int)prefixStart) < offset) {
        dictEnd = local_24 + local_28;
        extMatch = dictEnd + (int)(op + (-offset - (int)prefixStart));
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
    } while (4 < (uint)((int)oend - (int)op));
    iVar2 = -1;
LAB_000d1b92:
    if (0 < iVar2) {
      lz4sd->prefixSize = lz4sd->prefixSize + originalSize;
      lz4sd->prefixEnd = lz4sd->prefixEnd + originalSize;
    }
  }
  else {
    (LZ4_streamDecode->internal_donotuse).extDictSize =
         (LZ4_streamDecode->internal_donotuse).prefixSize;
    (LZ4_streamDecode->internal_donotuse).externalDict =
         (LZ4_streamDecode->internal_donotuse).prefixEnd +
         -(LZ4_streamDecode->internal_donotuse).extDictSize;
    iVar2 = LZ4_decompress_fast_extDict
                      (source,dest,originalSize,(LZ4_streamDecode->internal_donotuse).externalDict,
                       (LZ4_streamDecode->internal_donotuse).extDictSize);
    if (0 < iVar2) {
      lz4sd->prefixSize = originalSize;
      lz4sd->prefixEnd = (LZ4_byte *)(dest + originalSize);
    }
  }
  return iVar2;
}

