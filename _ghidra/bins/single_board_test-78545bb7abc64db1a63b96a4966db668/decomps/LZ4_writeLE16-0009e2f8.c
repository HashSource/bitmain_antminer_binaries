
void LZ4_writeLE16(void *memPtr,U16 value)

{
  uint uVar1;
  U16 value_local;
  void *memPtr_local;
  BYTE *p;
  
  uVar1 = LZ4_isLittleEndian();
  if (uVar1 == 0) {
    *(U16 *)memPtr = value;
  }
  else {
    LZ4_write16(memPtr,value);
  }
  return;
}

