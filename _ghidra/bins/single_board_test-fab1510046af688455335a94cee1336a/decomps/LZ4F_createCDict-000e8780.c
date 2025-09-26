
LZ4F_CDict * LZ4F_createCDict(void *dictBuffer,size_t dictSize)

{
  LZ4F_CDict *pLVar1;
  size_t dictSize_local;
  void *dictBuffer_local;
  
  pLVar1 = LZ4F_createCDict_advanced((LZ4F_CustomMem)ZEXT816((ulonglong)0),dictBuffer,dictSize);
  return pLVar1;
}

