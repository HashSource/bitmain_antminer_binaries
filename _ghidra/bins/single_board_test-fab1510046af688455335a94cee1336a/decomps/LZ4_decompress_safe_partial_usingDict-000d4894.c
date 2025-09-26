
int LZ4_decompress_safe_partial_usingDict
              (char *source,char *dest,int compressedSize,int targetOutputSize,int dstCapacity,
              char *dictStart,int dictSize)

{
  int iVar1;
  int targetOutputSize_local;
  int compressedSize_local;
  char *dest_local;
  char *source_local;
  
  if (dictSize == 0) {
    iVar1 = LZ4_decompress_safe_partial(source,dest,compressedSize,targetOutputSize,dstCapacity);
  }
  else if (dictStart + dictSize == dest) {
    if (dictSize < 0xffff) {
      iVar1 = LZ4_decompress_safe_partial_withSmallPrefix
                        (source,dest,compressedSize,targetOutputSize,dstCapacity,dictSize);
    }
    else {
      iVar1 = LZ4_decompress_safe_partial_withPrefix64k
                        (source,dest,compressedSize,targetOutputSize,dstCapacity);
    }
  }
  else {
    iVar1 = LZ4_decompress_safe_partial_forceExtDict
                      (source,dest,compressedSize,targetOutputSize,dstCapacity,dictStart,dictSize);
  }
  return iVar1;
}

