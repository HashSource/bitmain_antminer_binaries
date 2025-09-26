
/* WARNING: Removing unreachable block (ram,0x000b88c8) */

int LZ4_loadDict(LZ4_stream_t *LZ4_dict,char *dictionary,int dictSize)

{
  U32 UVar1;
  LZ4_u32 LVar2;
  uint uVar3;
  int dictSize_local;
  char *dictionary_local;
  LZ4_stream_t *LZ4_dict_local;
  U16 *hashTable_2;
  U32 *hashTable_1;
  BYTE **hashTable;
  U32 h;
  BYTE *base;
  BYTE *dictEnd;
  tableType_t tableType;
  LZ4_stream_t_internal *dict;
  BYTE *p;
  
  LZ4_resetStream(LZ4_dict);
  (LZ4_dict->internal_donotuse).currentOffset =
       (LZ4_dict->internal_donotuse).currentOffset + 0x10000;
  if (dictSize < 4) {
    LVar2 = 0;
  }
  else {
    p = (BYTE *)dictionary;
    if (0x10000 < dictSize) {
      p = (BYTE *)(dictionary + dictSize + -0x10000);
    }
    LVar2 = (LZ4_dict->internal_donotuse).currentOffset;
    (LZ4_dict->internal_donotuse).dictionary = p;
    (LZ4_dict->internal_donotuse).dictSize = (LZ4_u32)(dictionary + (dictSize - (int)p));
    (LZ4_dict->internal_donotuse).tableType = 2;
    for (; p <= dictionary + dictSize + -4; p = p + 3) {
      UVar1 = LZ4_read32(p);
      uVar3 = UVar1 * -0x61c8864f >> 0x14;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(0xb892e) {
      case 1:
                    /* WARNING: This code block may not be properly labeled as switch case */
        *(BYTE **)(uVar3 * 4 + (int)LZ4_dict) = p;
        break;
      case 2:
                    /* WARNING: This code block may not be properly labeled as switch case */
        *(int *)(uVar3 * 4 + (int)LZ4_dict) = (int)p - (int)(dictionary + (dictSize - LVar2));
        break;
      case 3:
                    /* WARNING: This code block may not be properly labeled as switch case */
        *(short *)(uVar3 * 2 + (int)LZ4_dict) = (short)p - (short)(dictionary + (dictSize - LVar2));
      }
                    /* WARNING: This code block may not be properly labeled as switch case */
    }
    LVar2 = (LZ4_dict->internal_donotuse).dictSize;
  }
  return LVar2;
}

