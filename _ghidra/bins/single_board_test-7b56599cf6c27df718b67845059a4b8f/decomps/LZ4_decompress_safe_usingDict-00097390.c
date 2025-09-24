
int LZ4_decompress_safe_usingDict
              (char *source,char *dest,int compressedSize,int maxOutputSize,char *dictStart,
              int dictSize)

{
  int iVar1;
  int maxOutputSize_local;
  int compressedSize_local;
  char *dest_local;
  char *source_local;
  
  if (dictSize == 0) {
    iVar1 = LZ4_decompress_safe(source,dest,compressedSize,maxOutputSize);
  }
  else if (dictStart + dictSize == dest) {
    if (dictSize < 0xffff) {
      iVar1 = LZ4_decompress_safe_withSmallPrefix(source,dest,compressedSize,maxOutputSize,dictSize)
      ;
    }
    else {
      iVar1 = LZ4_decompress_safe_withPrefix64k(source,dest,compressedSize,maxOutputSize);
    }
  }
  else {
    iVar1 = LZ4_decompress_safe_forceExtDict
                      (source,dest,compressedSize,maxOutputSize,dictStart,dictSize);
  }
  return iVar1;
}

