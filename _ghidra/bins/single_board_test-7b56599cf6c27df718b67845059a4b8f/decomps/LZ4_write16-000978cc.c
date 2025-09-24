
void LZ4_write16(void *memPtr,U16 value)

{
  U16 value_local;
  void *memPtr_local;
  
  *(U16 *)memPtr = value;
  return;
}

