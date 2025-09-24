
void LZ4_write32(void *memPtr,U32 value)

{
  U32 value_local;
  void *memPtr_local;
  
  *(U32 *)memPtr = value;
  return;
}

