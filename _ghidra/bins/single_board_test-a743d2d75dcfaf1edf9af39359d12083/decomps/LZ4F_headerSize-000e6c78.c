
size_t LZ4F_headerSize(void *src,size_t srcSize)

{
  LZ4F_errorCode_t LVar1;
  U32 UVar2;
  int iVar3;
  int iVar4;
  size_t srcSize_local;
  void *src_local;
  U32 dictIDFlag;
  U32 contentSizeFlag;
  BYTE FLG;
  
  if (src == (void *)0x0) {
    LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_srcPtr_wrong);
  }
  else if (srcSize < 5) {
    LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_frameHeader_incomplete);
  }
  else {
    UVar2 = LZ4F_readLE32(src);
    if ((UVar2 & 0xfffffff0) == 0x184d2a50) {
      LVar1 = 8;
    }
    else {
      UVar2 = LZ4F_readLE32(src);
      if (UVar2 == 0x184d2204) {
        if ((*(byte *)((int)src + 4) >> 3 & 1) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = 8;
        }
        if ((*(byte *)((int)src + 4) & 1) == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = 4;
        }
        LVar1 = iVar4 + iVar3 + 7;
      }
      else {
        LVar1 = LZ4F_returnErrorCode(LZ4F_ERROR_frameType_unknown);
      }
    }
  }
  return LVar1;
}

