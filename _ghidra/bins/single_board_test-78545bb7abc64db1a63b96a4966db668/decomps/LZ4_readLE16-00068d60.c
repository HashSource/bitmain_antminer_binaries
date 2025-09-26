
U16 LZ4_readLE16(void *memPtr)

{
  U16 UVar1;
  uint uVar2;
  void *memPtr_local;
  BYTE *p;
  
  uVar2 = LZ4_isLittleEndian();
  if (uVar2 == 0) {
                    /* WARNING: Load size is inaccurate */
    UVar1 = (ushort)*(byte *)((int)memPtr + 1) * 0x100 + (ushort)*memPtr;
  }
  else {
    UVar1 = LZ4_read16(memPtr);
  }
  return UVar1;
}

