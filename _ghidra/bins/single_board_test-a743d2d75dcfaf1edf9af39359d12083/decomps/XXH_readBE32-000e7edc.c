
U32 XXH_readBE32(void *ptr)

{
  int iVar1;
  U32 UVar2;
  void *ptr_local;
  
  iVar1 = XXH_isLittleEndian();
  if (iVar1 == 0) {
    UVar2 = XXH_read32(ptr);
  }
  else {
    UVar2 = XXH_read32(ptr);
    UVar2 = UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 | (UVar2 >> 0x10 & 0xff) << 8 |
            UVar2 >> 0x18;
  }
  return UVar2;
}

