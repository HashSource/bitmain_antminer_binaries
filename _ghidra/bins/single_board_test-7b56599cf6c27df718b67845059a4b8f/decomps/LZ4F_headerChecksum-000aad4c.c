
BYTE LZ4F_headerChecksum(void *header,size_t length)

{
  uint uVar1;
  size_t length_local;
  void *header_local;
  U32 xxh;
  
  uVar1 = XXH32(header,length,0);
  return (BYTE)(uVar1 >> 8);
}

