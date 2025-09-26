
BYTE * LZ4_getPositionOnHash(U32 h,void *tableBase,tableType_t tableType,BYTE *srcBase)

{
  BYTE *pBVar1;
  BYTE *srcBase_local;
  tableType_t tableType_local;
  void *tableBase_local;
  U32 h_local;
  U16 *hashTable_2;
  U32 *hashTable_1;
  BYTE **hashTable;
  
  if (tableType == byPtr) {
    pBVar1 = *(BYTE **)(h * 4 + (int)tableBase);
  }
  else if (tableType == byU32) {
    pBVar1 = srcBase + *(int *)(h * 4 + (int)tableBase);
  }
  else {
    pBVar1 = srcBase + *(ushort *)(h * 2 + (int)tableBase);
  }
  return pBVar1;
}

