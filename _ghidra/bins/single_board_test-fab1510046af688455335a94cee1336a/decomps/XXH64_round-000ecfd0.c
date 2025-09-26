
U64 XXH64_round(U64 acc,U64 input)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  U64 input_local;
  U64 acc_local;
  
  uVar2 = acc + input * -0x3d4d51c2d82b14b1;
  uVar3 = uVar2 >> 1;
  uVar4 = (uint)(uVar3 >> 0x20) | (int)uVar2 << 0x1f;
  lVar1 = (ulonglong)uVar4 * 0x85ebca87;
  return CONCAT44(uVar4 * -0x61c8864f + (int)uVar3 * -0x7a143579 + (int)((ulonglong)lVar1 >> 0x20),
                  (int)lVar1);
}

