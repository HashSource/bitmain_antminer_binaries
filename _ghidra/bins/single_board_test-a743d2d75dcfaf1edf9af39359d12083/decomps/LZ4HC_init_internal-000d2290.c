
void LZ4HC_init_internal(LZ4HC_CCtx_internal *hc4,BYTE *start)

{
  LZ4_u32 LVar1;
  BYTE *start_local;
  LZ4HC_CCtx_internal *hc4_local;
  size_t bufferSize;
  size_t newStartingOffset;
  
  newStartingOffset = (size_t)(hc4->end + (hc4->dictLimit - (int)hc4->prefixStart));
  if ((LZ4_byte *)0x40000000 < newStartingOffset) {
    LZ4HC_clearTables(hc4);
    newStartingOffset = 0;
  }
  LVar1 = newStartingOffset + 0x10000;
  hc4->nextToUpdate = LVar1;
  hc4->prefixStart = start;
  hc4->end = start;
  hc4->dictStart = start;
  hc4->dictLimit = LVar1;
  hc4->lowLimit = LVar1;
  return;
}

