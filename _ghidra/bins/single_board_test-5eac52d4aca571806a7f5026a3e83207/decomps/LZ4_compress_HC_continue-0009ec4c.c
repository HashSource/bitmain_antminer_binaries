
int LZ4_compress_HC_continue
              (LZ4_streamHC_t *LZ4_streamHCPtr,char *src,char *dst,int srcSize,int dstCapacity)

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  
  srcSize_local = srcSize;
  dst_local = dst;
  src_local = src;
  LZ4_streamHCPtr_local = LZ4_streamHCPtr;
  iVar1 = LZ4_compressBound(srcSize);
  if (dstCapacity < iVar1) {
    iVar1 = LZ4_compressHC_continue_generic
                      (LZ4_streamHCPtr_local,src_local,dst_local,&srcSize_local,dstCapacity,
                       limitedOutput);
  }
  else {
    iVar1 = LZ4_compressHC_continue_generic
                      (LZ4_streamHCPtr_local,src_local,dst_local,&srcSize_local,dstCapacity,
                       notLimited);
  }
  return iVar1;
}

