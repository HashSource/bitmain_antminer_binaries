
U32 LZ4HC_hashPtr(void *ptr)

{
  U32 UVar1;
  void *ptr_local;
  
  UVar1 = LZ4_read32(ptr);
  return UVar1 * -0x61c8864f >> 0x11;
}

