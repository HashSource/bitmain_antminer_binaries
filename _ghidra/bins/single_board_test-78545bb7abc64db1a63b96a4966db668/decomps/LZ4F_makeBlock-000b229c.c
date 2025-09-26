
size_t LZ4F_makeBlock(void *dst,void *src,size_t srcSize,compressFunc_t compress,void *lz4ctx,
                     int level,LZ4F_CDict *cdict,LZ4F_blockChecksum_t crcFlag)

{
  uint value32;
  compressFunc_t compress_local;
  size_t srcSize_local;
  void *src_local;
  void *dst_local;
  U32 crc32;
  BYTE *cSizePtr;
  U32 cSize;
  
  cSize = (*compress)(lz4ctx,(char *)src,(char *)((int)dst + 4),srcSize,srcSize - 1,level,cdict);
  if ((cSize == 0) || (srcSize <= cSize)) {
    LZ4F_writeLE32(dst,srcSize | 0x80000000);
    memcpy((void *)((int)dst + 4),src,srcSize);
    cSize = srcSize;
  }
  else {
    LZ4F_writeLE32(dst,cSize);
  }
  if (crcFlag != LZ4F_noBlockChecksum) {
    value32 = XXH32((void *)((int)dst + 4),cSize,0);
    LZ4F_writeLE32((void *)(cSize + 4 + (int)dst),value32);
  }
  return crcFlag * 4 + cSize + 4;
}

