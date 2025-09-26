
int LZ4_compressHC2_limitedOutput_continue
              (void *LZ4HC_Data,char *src,char *dst,int srcSize,int dstCapacity,int cLevel)

{
  int iVar1;
  int srcSize_local;
  char *dst_local;
  char *src_local;
  void *LZ4HC_Data_local;
  
  srcSize_local = srcSize;
  dst_local = dst;
  src_local = src;
  LZ4HC_Data_local = LZ4HC_Data;
  iVar1 = LZ4HC_compress_generic
                    ((LZ4HC_CCtx_internal *)LZ4HC_Data,src,dst,&srcSize_local,dstCapacity,cLevel,
                     limitedOutput);
  return iVar1;
}

