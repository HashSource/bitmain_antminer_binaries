
LZ4F_errorCode_t LZ4F_writeClose(LZ4_writeFile_t *lz4fWrite)

{
  uint uVar1;
  size_t sVar2;
  LZ4_writeFile_t *lz4fWrite_local;
  LZ4F_errorCode_t ret;
  
  ret = 0;
  if (lz4fWrite == (LZ4_writeFile_t *)0x0) {
    ret = 0xffffffff;
  }
  else {
    if (lz4fWrite->errCode == 0) {
      ret = LZ4F_compressEnd(lz4fWrite->cctxPtr,lz4fWrite->dstBuf,lz4fWrite->dstBufMaxSize,
                             (LZ4F_compressOptions_t *)0x0);
      uVar1 = LZ4F_isError(ret);
      if ((uVar1 == 0) &&
         (sVar2 = fwrite(lz4fWrite->dstBuf,1,ret,(FILE *)lz4fWrite->fp), sVar2 != ret)) {
        ret = 0xffffffff;
      }
    }
    LZ4F_freeCompressionContext(lz4fWrite->cctxPtr);
    free(lz4fWrite->dstBuf);
    free(lz4fWrite);
  }
  return ret;
}

