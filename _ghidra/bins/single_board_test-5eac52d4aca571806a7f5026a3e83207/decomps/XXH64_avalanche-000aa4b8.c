
U64 XXH64_avalanche(U64 h64)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  U64 h64_local;
  
  h64_local._4_4_ = (uint)(h64 >> 0x20);
  h64_local._0_4_ = (uint)h64;
  uVar3 = (uint)h64_local ^ h64_local._4_4_ >> 1;
  lVar1 = (ulonglong)uVar3 * 0x27d4eb4f;
  uVar2 = h64_local._4_4_ * 0x27d4eb4f + uVar3 * -0x3d4d51c3 + (int)((ulonglong)lVar1 >> 0x20);
  uVar3 = (uint)lVar1;
  uVar3 = (uVar3 >> 0x1d | uVar2 * 8) ^ uVar3;
  lVar1 = (ulonglong)uVar3 * 0x9e3779f9;
  uVar3 = uVar3 * 0x165667b1 + (uVar2 >> 0x1d ^ uVar2) * -0x61c88607 +
          (int)((ulonglong)lVar1 >> 0x20);
  h64_local = CONCAT44(uVar3,(uint)lVar1 ^ uVar3);
  return h64_local;
}

