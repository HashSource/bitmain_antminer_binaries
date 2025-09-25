
size_t LZ4F_compressBound(size_t srcSize,LZ4F_preferences_t *preferencesPtr)

{
  size_t sVar1;
  LZ4F_preferences_t *preferencesPtr_local;
  size_t srcSize_local;
  
  if ((preferencesPtr == (LZ4F_preferences_t *)0x0) || (preferencesPtr->autoFlush == 0)) {
    sVar1 = LZ4F_compressBound_internal(srcSize,preferencesPtr,0xffffffff);
  }
  else {
    sVar1 = LZ4F_compressBound_internal(srcSize,preferencesPtr,0);
  }
  return sVar1;
}

