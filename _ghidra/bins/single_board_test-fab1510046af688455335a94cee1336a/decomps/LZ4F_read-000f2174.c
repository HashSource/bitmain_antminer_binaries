
/* WARNING: Removing unreachable block (ram,0x000f21e8) */

size_t LZ4F_read(LZ4_readFile_t *lz4fRead,void *buf,size_t size)

{
  uint uVar1;
  size_t size_local;
  void *buf_local;
  LZ4_readFile_t *lz4fRead_local;
  size_t dstsize;
  size_t srcsize;
  size_t ret;
  size_t next;
  LZ4_byte *p;
  
  next = 0;
  if ((lz4fRead == (LZ4_readFile_t *)0x0) || (p = (LZ4_byte *)buf, buf == (void *)0x0)) {
    next = 0xffffffff;
  }
  else {
    for (; next < size; next = dstsize + next) {
      srcsize = lz4fRead->srcBufSize - lz4fRead->srcBufNext;
      dstsize = size - next;
      if (srcsize == 0) {
        ret = fread(lz4fRead->srcBuf,1,lz4fRead->srcBufMaxSize,(FILE *)lz4fRead->fp);
        if (ret == 0) {
          return next;
        }
        lz4fRead->srcBufSize = ret;
        srcsize = lz4fRead->srcBufSize;
        lz4fRead->srcBufNext = 0;
      }
      ret = LZ4F_decompress(lz4fRead->dctxPtr,p,&dstsize,lz4fRead->srcBuf + lz4fRead->srcBufNext,
                            &srcsize,(LZ4F_decompressOptions_t *)0x0);
      uVar1 = LZ4F_isError(ret);
      if (uVar1 != 0) {
        return ret;
      }
      lz4fRead->srcBufNext = lz4fRead->srcBufNext + srcsize;
      p = p + dstsize;
    }
  }
  return next;
}

