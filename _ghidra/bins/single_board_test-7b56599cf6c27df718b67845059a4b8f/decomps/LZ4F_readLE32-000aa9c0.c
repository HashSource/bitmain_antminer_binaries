
U32 LZ4F_readLE32(void *src)

{
  void *src_local;
  U32 value32;
  BYTE *srcPtr;
  
                    /* WARNING: Load size is inaccurate */
  return (uint)*(byte *)((int)src + 3) * 0x1000000 +
         (uint)*(byte *)((int)src + 2) * 0x10000 +
         (uint)*(byte *)((int)src + 1) * 0x100 + (uint)*src;
}

