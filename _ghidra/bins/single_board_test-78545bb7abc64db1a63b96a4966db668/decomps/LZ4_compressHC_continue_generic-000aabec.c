
int LZ4_compressHC_continue_generic
              (LZ4_streamHC_t *LZ4_streamHCPtr,char *src,char *dst,int *srcSizePtr,int dstCapacity,
              limitedOutput_directive limit)

{
  int iVar1;
  LZ4_byte *pLVar2;
  int *srcSizePtr_local;
  char *dst_local;
  char *src_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  BYTE *dictEnd;
  BYTE *dictBegin;
  LZ4HC_CCtx_internal *ctxPtr;
  BYTE *sourceEnd;
  size_t dictSize;
  
  if ((LZ4_streamHCPtr->internal_donotuse).prefixStart == (LZ4_byte *)0x0) {
    LZ4HC_init_internal(&LZ4_streamHCPtr->internal_donotuse,(BYTE *)src);
  }
  if ((LZ4_byte *)0x80000000 <
      (LZ4_streamHCPtr->internal_donotuse).end +
      ((LZ4_streamHCPtr->internal_donotuse).dictLimit -
      (int)(LZ4_streamHCPtr->internal_donotuse).prefixStart)) {
    dictSize = (int)(LZ4_streamHCPtr->internal_donotuse).end -
               (int)(LZ4_streamHCPtr->internal_donotuse).prefixStart;
    if (0x10000 < dictSize) {
      dictSize = 0x10000;
    }
    LZ4_loadDictHC(LZ4_streamHCPtr,(char *)((LZ4_streamHCPtr->internal_donotuse).end + -dictSize),
                   dictSize);
  }
  if ((LZ4_streamHCPtr->internal_donotuse).end != (LZ4_byte *)src) {
    LZ4HC_setExternalDict(&LZ4_streamHCPtr->internal_donotuse,(BYTE *)src);
  }
  sourceEnd = (BYTE *)(src + *srcSizePtr);
  pLVar2 = (LZ4_streamHCPtr->internal_donotuse).dictStart +
           ((LZ4_streamHCPtr->internal_donotuse).dictLimit -
           (LZ4_streamHCPtr->internal_donotuse).lowLimit);
  if (((LZ4_streamHCPtr->internal_donotuse).dictStart < sourceEnd) && (src < pLVar2)) {
    if (pLVar2 < sourceEnd) {
      sourceEnd = pLVar2;
    }
    (LZ4_streamHCPtr->internal_donotuse).lowLimit =
         (LZ4_u32)(sourceEnd +
                  ((LZ4_streamHCPtr->internal_donotuse).lowLimit -
                  (int)(LZ4_streamHCPtr->internal_donotuse).dictStart));
    (LZ4_streamHCPtr->internal_donotuse).dictStart =
         (LZ4_streamHCPtr->internal_donotuse).dictStart +
         ((int)sourceEnd - (int)(LZ4_streamHCPtr->internal_donotuse).dictStart);
    if ((LZ4_streamHCPtr->internal_donotuse).dictLimit -
        (LZ4_streamHCPtr->internal_donotuse).lowLimit < 4) {
      (LZ4_streamHCPtr->internal_donotuse).lowLimit = (LZ4_streamHCPtr->internal_donotuse).dictLimit
      ;
      (LZ4_streamHCPtr->internal_donotuse).dictStart =
           (LZ4_streamHCPtr->internal_donotuse).prefixStart;
    }
  }
  iVar1 = LZ4HC_compress_generic
                    (&LZ4_streamHCPtr->internal_donotuse,src,dst,srcSizePtr,dstCapacity,
                     (int)(LZ4_streamHCPtr->internal_donotuse).compressionLevel,limit);
  return iVar1;
}

