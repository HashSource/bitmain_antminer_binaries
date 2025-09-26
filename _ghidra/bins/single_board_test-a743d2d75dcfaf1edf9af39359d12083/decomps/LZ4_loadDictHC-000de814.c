
int LZ4_loadDictHC(LZ4_streamHC_t *LZ4_streamHCPtr,char *dictionary,int dictSize)

{
  short sVar1;
  U32 UVar2;
  LZ4_byte *pLVar3;
  LZ4_byte *pLVar4;
  LZ4_u32 LVar5;
  int dictSize_local;
  char *dictionary_local;
  LZ4_streamHC_t *LZ4_streamHCPtr_local;
  size_t delta;
  U32 h;
  U32 idx;
  U32 target;
  U32 prefixIdx;
  BYTE *prefixPtr;
  U32 *hashTable;
  U16 *chainTable;
  int cLevel;
  LZ4HC_CCtx_internal *ctxPtr;
  
  dictSize_local = dictSize;
  dictionary_local = dictionary;
  if (0x10000 < dictSize) {
    dictionary_local = dictionary + dictSize + -0x10000;
    dictSize_local = 0x10000;
  }
  sVar1 = (LZ4_streamHCPtr->internal_donotuse).compressionLevel;
  LZ4_initStreamHC(LZ4_streamHCPtr,0x40038);
  LZ4_setCompressionLevel(LZ4_streamHCPtr,(int)sVar1);
  LZ4HC_init_internal(&LZ4_streamHCPtr->internal_donotuse,(BYTE *)dictionary_local);
  (LZ4_streamHCPtr->internal_donotuse).end = (LZ4_byte *)(dictionary_local + dictSize_local);
  if (3 < dictSize_local) {
    pLVar3 = (LZ4_streamHCPtr->internal_donotuse).end;
    pLVar4 = (LZ4_streamHCPtr->internal_donotuse).prefixStart;
    LVar5 = (LZ4_streamHCPtr->internal_donotuse).dictLimit;
    for (idx = (LZ4_streamHCPtr->internal_donotuse).nextToUpdate;
        idx < pLVar3 + LVar5 + (-3 - (int)pLVar4); idx = idx + 1) {
      UVar2 = LZ4HC_hashPtr(pLVar4 + (idx - LVar5));
      delta = idx - *(int *)(UVar2 * 4 + (int)LZ4_streamHCPtr);
      if (0xffff < delta) {
        delta = 0xffff;
      }
      *(short *)((int)LZ4_streamHCPtr + (idx & 0xffff) * 2 + 0x20000) = (short)delta;
      *(U32 *)(UVar2 * 4 + (int)LZ4_streamHCPtr) = idx;
    }
    (LZ4_streamHCPtr->internal_donotuse).nextToUpdate =
         (LZ4_u32)(pLVar3 + LVar5 + (-3 - (int)pLVar4));
  }
  return dictSize_local;
}

