
int LZ4_saveDict(LZ4_stream_t *LZ4_dict,char *safeBuffer,int dictSize)

{
  int dictSize_local;
  char *safeBuffer_local;
  LZ4_stream_t *LZ4_dict_local;
  BYTE *previousDictEnd;
  LZ4_stream_t_internal *dict;
  
  dictSize_local = dictSize;
  if (0x10000 < (uint)dictSize) {
    dictSize_local = 0x10000;
  }
  if ((LZ4_dict->internal_donotuse).dictSize < (uint)dictSize_local) {
    dictSize_local = (LZ4_dict->internal_donotuse).dictSize;
  }
  if (0 < dictSize_local) {
    memmove(safeBuffer,
            (LZ4_dict->internal_donotuse).dictionary +
            ((LZ4_dict->internal_donotuse).dictSize - dictSize_local),dictSize_local);
  }
  (LZ4_dict->internal_donotuse).dictionary = (LZ4_byte *)safeBuffer;
  (LZ4_dict->internal_donotuse).dictSize = dictSize_local;
  return dictSize_local;
}

