
void LZ4HC_setExternalDict(LZ4HC_CCtx_internal *ctxPtr,BYTE *newBlock)

{
  U32 UVar1;
  LZ4_byte *pLVar2;
  LZ4_byte *pLVar3;
  LZ4_u32 LVar4;
  BYTE *newBlock_local;
  LZ4HC_CCtx_internal *ctxPtr_local;
  size_t delta;
  U32 h;
  U32 idx;
  U32 target;
  U32 prefixIdx;
  BYTE *prefixPtr;
  U32 *hashTable;
  U16 *chainTable;
  
  if (ctxPtr->prefixStart + 4 <= ctxPtr->end) {
    pLVar2 = ctxPtr->end;
    pLVar3 = ctxPtr->prefixStart;
    LVar4 = ctxPtr->dictLimit;
    for (idx = ctxPtr->nextToUpdate; idx < pLVar2 + LVar4 + (-3 - (int)pLVar3); idx = idx + 1) {
      UVar1 = LZ4HC_hashPtr(pLVar3 + (idx - LVar4));
      delta = idx - ctxPtr->hashTable[UVar1];
      if (0xffff < delta) {
        delta = 0xffff;
      }
      ctxPtr->chainTable[idx & 0xffff] = (LZ4_u16)delta;
      ctxPtr->hashTable[UVar1] = idx;
    }
    ctxPtr->nextToUpdate = (LZ4_u32)(pLVar2 + LVar4 + (-3 - (int)pLVar3));
  }
  ctxPtr->lowLimit = ctxPtr->dictLimit;
  ctxPtr->dictStart = ctxPtr->prefixStart;
  ctxPtr->dictLimit = (LZ4_u32)(ctxPtr->end + (ctxPtr->dictLimit - (int)ctxPtr->prefixStart));
  ctxPtr->prefixStart = newBlock;
  ctxPtr->end = newBlock;
  ctxPtr->nextToUpdate = ctxPtr->dictLimit;
  ctxPtr->dictCtx = (LZ4HC_CCtx_internal *)0x0;
  return;
}

