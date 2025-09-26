
void LZ4F_writeLE32(void *dst,U32 value32)

{
  U32 value32_local;
  void *dst_local;
  BYTE *dstPtr;
  
  *(char *)dst = (char)value32;
  *(char *)((int)dst + 1) = (char)(value32 >> 8);
  *(char *)((int)dst + 2) = (char)(value32 >> 0x10);
  *(char *)((int)dst + 3) = (char)(value32 >> 0x18);
  return;
}

