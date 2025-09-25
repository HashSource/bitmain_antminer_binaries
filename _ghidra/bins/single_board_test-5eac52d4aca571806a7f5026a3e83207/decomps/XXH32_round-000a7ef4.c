
U32 XXH32_round(U32 seed,U32 input)

{
  uint uVar1;
  U32 input_local;
  U32 seed_local;
  
  uVar1 = input * -0x7a143589 + seed;
  return (uVar1 >> 0x13 | uVar1 * 0x2000) * -0x61c8864f;
}

