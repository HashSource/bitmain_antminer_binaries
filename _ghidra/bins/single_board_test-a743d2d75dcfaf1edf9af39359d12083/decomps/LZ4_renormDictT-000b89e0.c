
void LZ4_renormDictT(LZ4_stream_t_internal *LZ4_dict,int nextSize)

{
  LZ4_byte *pLVar1;
  uint uVar2;
  LZ4_u32 LVar3;
  int nextSize_local;
  LZ4_stream_t_internal *LZ4_dict_local;
  BYTE *dictEnd;
  U32 delta;
  int i;
  
  if (0x80000000 < nextSize + LZ4_dict->currentOffset) {
    uVar2 = LZ4_dict->currentOffset - 0x10000;
    pLVar1 = LZ4_dict->dictionary;
    LVar3 = LZ4_dict->dictSize;
    for (i = 0; i < 0x1000; i = i + 1) {
      if (LZ4_dict->hashTable[i] < uVar2) {
        LZ4_dict->hashTable[i] = 0;
      }
      else {
        LZ4_dict->hashTable[i] = LZ4_dict->hashTable[i] - uVar2;
      }
    }
    LZ4_dict->currentOffset = 0x10000;
    if (0x10000 < LZ4_dict->dictSize) {
      LZ4_dict->dictSize = 0x10000;
    }
    LZ4_dict->dictionary = pLVar1 + (LVar3 - LZ4_dict->dictSize);
  }
  return;
}

