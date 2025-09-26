
int LZ4_isAligned(void *ptr,size_t alignment)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  size_t alignment_local;
  void *ptr_local;
  
  uVar2 = (uint)ptr & alignment - 1;
  bVar3 = uVar2 == 0;
  if (bVar3) {
    uVar2 = 1;
  }
  bVar1 = (byte)uVar2;
  if (!bVar3) {
    bVar1 = 0;
  }
  return (uint)bVar1;
}

