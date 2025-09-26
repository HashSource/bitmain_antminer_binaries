
int LZ4_compress_HC_continue_destSize
              (LZ4_streamHC_t *LZ4_streamHCPtr,char *src,char *dst,int *srcSizePtr,
              int targetDestSize)

{
  int iVar1;
  int *srcSizePtr_local;
  char *dst_local;
  char *src_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  
  iVar1 = LZ4_compressHC_continue_generic
                    (LZ4_streamHCPtr,src,dst,srcSizePtr,targetDestSize,fillOutput);
  return iVar1;
}

