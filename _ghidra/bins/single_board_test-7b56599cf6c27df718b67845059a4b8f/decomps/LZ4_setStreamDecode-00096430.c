
int LZ4_setStreamDecode(LZ4_streamDecode_t *LZ4_streamDecode,char *dictionary,int dictSize)

{
  int dictSize_local;
  char *dictionary_local;
  LZ4_streamDecode_t *LZ4_streamDecode_local;
  LZ4_streamDecode_t_internal *lz4sd;
  
  (LZ4_streamDecode->internal_donotuse).prefixSize = dictSize;
  if (dictSize == 0) {
    (LZ4_streamDecode->internal_donotuse).prefixEnd = (LZ4_byte *)dictionary;
  }
  else {
    (LZ4_streamDecode->internal_donotuse).prefixEnd = (LZ4_byte *)(dictionary + dictSize);
  }
  (LZ4_streamDecode->internal_donotuse).externalDict = (LZ4_byte *)0x0;
  (LZ4_streamDecode->internal_donotuse).extDictSize = 0;
  return 1;
}

