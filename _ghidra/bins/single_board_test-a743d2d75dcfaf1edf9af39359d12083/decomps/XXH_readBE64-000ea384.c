
U64 XXH_readBE64(void *ptr)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  U64 UVar4;
  void *ptr_local;
  
  iVar1 = XXH_isLittleEndian();
  if (iVar1 == 0) {
    UVar4 = XXH_read64(ptr);
  }
  else {
    UVar4 = XXH_read64(ptr);
    uVar3 = (uint)(UVar4 >> 0x20);
    uVar2 = (uint)UVar4;
    UVar4 = CONCAT44((int)(UVar4 & 0xff000000ff) << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 |
                     (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18,
                     (int)((UVar4 & 0xff000000ff) >> 0x20) << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                     (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18);
  }
  return UVar4;
}

