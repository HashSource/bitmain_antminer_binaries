
U64 LZ4F_readLE64(void *src)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  void *src_local;
  U64 value64;
  BYTE *srcPtr;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = (uint)*(byte *)((int)src + 1) * 0x100;
  uVar2 = *src + uVar1;
  uVar5 = (uint)*(byte *)((int)src + 2) * 0x10000;
  uVar3 = uVar2 + uVar5;
  uVar4 = (uint)*(byte *)((int)src + 3) * 0x1000000;
  return CONCAT44((uint)*(byte *)((int)src + 6) * 0x10000 +
                  (uint)*(byte *)((int)src + 5) * 0x100 +
                  (uint)*(byte *)((int)src + 4) +
                  (uint)CARRY4((uint)*src,uVar1) + (uint)CARRY4(uVar2,uVar5) +
                  (uint)CARRY4(uVar3,uVar4) + (uint)*(byte *)((int)src + 7) * 0x1000000,
                  uVar3 + uVar4);
}

