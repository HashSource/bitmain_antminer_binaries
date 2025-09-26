
int LZ4_compressBound(int isize)

{
  int iVar1;
  int isize_local;
  
  if ((uint)isize < 0x7e000001) {
    iVar1 = isize + isize / 0xff + 0x10;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

