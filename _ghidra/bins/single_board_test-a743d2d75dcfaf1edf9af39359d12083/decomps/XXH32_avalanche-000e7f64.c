
U32 XXH32_avalanche(U32 h32)

{
  uint uVar1;
  U32 h32_local;
  
  uVar1 = (h32 >> 0xf ^ h32) * -0x7a143589;
  uVar1 = (uVar1 >> 0xd ^ uVar1) * -0x3d4d51c3;
  return uVar1 >> 0x10 ^ uVar1;
}

