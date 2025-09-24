
size_t LZ4F_write(LZ4_writeFile_t *lz4fWrite,void *buf,size_t size)

{
  size_t code;
  uint uVar1;
  size_t sVar2;
  size_t size_local;
  void *buf_local;
  LZ4_writeFile_t *lz4fWrite_local;
  size_t ret;
  size_t chunk;
  size_t remain;
  LZ4_byte *p;
  
  if ((lz4fWrite == (LZ4_writeFile_t *)0x0) ||
     (remain = size, p = (LZ4_byte *)buf, buf == (void *)0x0)) {
    size = 0xffffffff;
  }
  else {
    for (; remain != 0; remain = remain - chunk) {
      if (lz4fWrite->maxWriteSize < remain) {
        chunk = lz4fWrite->maxWriteSize;
      }
      else {
        chunk = remain;
      }
      code = LZ4F_compressUpdate(lz4fWrite->cctxPtr,lz4fWrite->dstBuf,lz4fWrite->dstBufMaxSize,p,
                                 chunk,(LZ4F_compressOptions_t *)0x0);
      uVar1 = LZ4F_isError(code);
      if (uVar1 != 0) {
        lz4fWrite->errCode = code;
        return code;
      }
      sVar2 = fwrite(lz4fWrite->dstBuf,1,code,(FILE *)lz4fWrite->fp);
      if (sVar2 != code) {
        lz4fWrite->errCode = 0xffffffff;
        return 0xffffffff;
      }
      p = p + chunk;
    }
  }
  return size;
}

