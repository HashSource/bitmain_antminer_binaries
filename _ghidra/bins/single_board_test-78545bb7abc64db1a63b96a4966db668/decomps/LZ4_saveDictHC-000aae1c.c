
int LZ4_saveDictHC(LZ4_streamHC_t *LZ4_streamHCPtr,char *safeBuffer,int dictSize)

{
  int iVar1;
  LZ4_byte *pLVar2;
  int dictSize_local;
  char *safeBuffer_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  U32 endIndex;
  int prefixSize;
  LZ4HC_CCtx_internal *streamPtr;
  
  iVar1 = (int)(LZ4_streamHCPtr->internal_donotuse).end -
          (int)(LZ4_streamHCPtr->internal_donotuse).prefixStart;
  dictSize_local = dictSize;
  if (0x10000 < dictSize) {
    dictSize_local = 0x10000;
  }
  if (dictSize_local < 4) {
    dictSize_local = 0;
  }
  if (iVar1 < dictSize_local) {
    dictSize_local = iVar1;
  }
  if (0 < dictSize_local) {
    memmove(safeBuffer,(LZ4_streamHCPtr->internal_donotuse).end + -dictSize_local,dictSize_local);
  }
  pLVar2 = (LZ4_streamHCPtr->internal_donotuse).end;
  iVar1 = (LZ4_streamHCPtr->internal_donotuse).dictLimit -
          (int)(LZ4_streamHCPtr->internal_donotuse).prefixStart;
  (LZ4_streamHCPtr->internal_donotuse).end = (LZ4_byte *)(safeBuffer + dictSize_local);
  (LZ4_streamHCPtr->internal_donotuse).prefixStart =
       (LZ4_streamHCPtr->internal_donotuse).end + -dictSize_local;
  (LZ4_streamHCPtr->internal_donotuse).dictLimit = (LZ4_u32)(pLVar2 + (iVar1 - dictSize_local));
  (LZ4_streamHCPtr->internal_donotuse).lowLimit = (LZ4_u32)(pLVar2 + (iVar1 - dictSize_local));
  (LZ4_streamHCPtr->internal_donotuse).dictStart = (LZ4_streamHCPtr->internal_donotuse).prefixStart;
  if ((LZ4_streamHCPtr->internal_donotuse).nextToUpdate <
      (LZ4_streamHCPtr->internal_donotuse).dictLimit) {
    (LZ4_streamHCPtr->internal_donotuse).nextToUpdate =
         (LZ4_streamHCPtr->internal_donotuse).dictLimit;
  }
  return dictSize_local;
}

