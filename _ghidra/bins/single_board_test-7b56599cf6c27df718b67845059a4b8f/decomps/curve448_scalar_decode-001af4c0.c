
uint curve448_scalar_decode(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint *puVar6;
  bool bVar7;
  bool bVar8;
  
  puVar6 = param_1 + -1;
  uVar3 = 0;
  do {
    uVar4 = 0;
    if (uVar3 != 0x38) {
      uVar1 = 0;
      pbVar5 = (byte *)(param_2 + uVar3);
      do {
        uVar3 = uVar3 + 1;
        uVar2 = uVar1 + 1;
        bVar8 = 2 < uVar2;
        bVar7 = uVar2 == 3;
        if (uVar2 < 4) {
          bVar8 = 0x36 < uVar3;
          bVar7 = uVar3 == 0x37;
        }
        uVar4 = uVar4 | (uint)*pbVar5 << ((uVar1 & 0x1f) << 3);
        uVar1 = uVar2;
        pbVar5 = pbVar5 + 1;
      } while (!bVar8 || bVar7);
    }
    puVar6 = puVar6 + 1;
    *puVar6 = uVar4;
  } while (param_1 + 0xd != puVar6);
  uVar3 = (0xab5844f2 < *param_1) - 1;
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[1]) + -1 +
          (uint)(0x2378c291 < uVar3 + param_1[1]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[2]) + -1 +
          (uint)(0x8dc58f54 < uVar3 + param_1[2]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[3]) + -1 +
          (uint)(0x216cc271 < uVar3 + param_1[3]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[4]) + -1 +
          (uint)(0xaed6368f < uVar3 + param_1[4]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[5]) + -1 +
          (uint)(0xc44edb48 < uVar3 + param_1[5]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[6]) + -1 +
          (uint)(0x7cca23e8 < uVar3 + param_1[6]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[7]) + -1 +
          (uint)(0xfffffffe < uVar3 + param_1[7]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[8]) + -1 +
          (uint)(0xfffffffe < uVar3 + param_1[8]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[9]) + -1 +
          (uint)(0xfffffffe < uVar3 + param_1[9]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[10]) + -1 +
          (uint)(0xfffffffe < uVar3 + param_1[10]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[0xb]) + -1 +
          (uint)(0xfffffffe < uVar3 + param_1[0xb]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[0xc]) + -1 +
          (uint)(0xfffffffe < uVar3 + param_1[0xc]);
  uVar3 = ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar3,param_1[0xd]) + -1 +
          (uint)(0x3ffffffe < uVar3 + param_1[0xd]);
  curve448_scalar_mul(param_1,param_1,curve448_scalar_one);
  return ~((int)(uVar3 - 1 & ~uVar3) >> 0x1f);
}

