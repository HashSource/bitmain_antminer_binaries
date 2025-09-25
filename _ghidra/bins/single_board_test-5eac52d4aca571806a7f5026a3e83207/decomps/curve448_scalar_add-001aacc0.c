
void curve448_scalar_add(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  uVar21 = *param_2 + *param_3;
  uVar2 = (uint)CARRY4(*param_3,*param_2);
  *param_1 = uVar21;
  uVar1 = param_3[1] + param_2[1];
  uVar4 = uVar2 + uVar1;
  uVar2 = (uint)CARRY4(param_3[1],param_2[1]) + (uint)CARRY4(uVar2,uVar1);
  param_1[1] = uVar4;
  uVar5 = param_3[2] + param_2[2];
  uVar1 = uVar2 + uVar5;
  uVar2 = (uint)CARRY4(param_3[2],param_2[2]) + (uint)CARRY4(uVar2,uVar5);
  uVar8 = (0xab5844f2 < uVar21) - 1;
  param_1[2] = uVar1;
  uVar6 = param_3[3] + param_2[3];
  uVar5 = uVar2 + uVar6;
  uVar2 = (uint)CARRY4(param_3[3],param_2[3]) + (uint)CARRY4(uVar2,uVar6);
  uVar3 = uVar8 + uVar4 + 0xdc873d6e;
  param_1[3] = uVar5;
  uVar6 = ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,uVar4) + ((0x2378c291 < uVar8 + uVar4) - 1);
  uVar4 = param_3[4] + param_2[4];
  uVar10 = uVar2 + uVar4;
  uVar2 = (uint)CARRY4(param_3[4],param_2[4]) + (uint)CARRY4(uVar2,uVar4);
  param_1[4] = uVar10;
  uVar4 = param_3[5] + param_2[5];
  uVar14 = uVar2 + uVar4;
  uVar2 = (uint)CARRY4(param_3[5],param_2[5]) + (uint)CARRY4(uVar2,uVar4);
  param_1[5] = uVar14;
  uVar4 = uVar6 + uVar1 + 0x723a70ab;
  uVar1 = ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,uVar1) + ((0x8dc58f54 < uVar6 + uVar1) - 1);
  uVar6 = param_3[6] + param_2[6];
  uVar11 = uVar2 + uVar6;
  uVar2 = (uint)CARRY4(param_3[6],param_2[6]) + (uint)CARRY4(uVar2,uVar6);
  param_1[6] = uVar11;
  uVar6 = param_3[7] + param_2[7];
  uVar17 = uVar2 + uVar6;
  uVar2 = (uint)CARRY4(param_3[7],param_2[7]) + (uint)CARRY4(uVar2,uVar6);
  param_1[7] = uVar17;
  uVar6 = param_3[8] + param_2[8];
  uVar12 = uVar2 + uVar6;
  uVar2 = (uint)CARRY4(param_3[8],param_2[8]) + (uint)CARRY4(uVar2,uVar6);
  param_1[8] = uVar12;
  uVar6 = param_3[9] + param_2[9];
  uVar15 = uVar2 + uVar6;
  uVar2 = (uint)CARRY4(param_3[9],param_2[9]) + (uint)CARRY4(uVar2,uVar6);
  param_1[9] = uVar15;
  uVar6 = param_3[10] + param_2[10];
  uVar18 = uVar2 + uVar6;
  uVar2 = (uint)CARRY4(param_3[10],param_2[10]) + (uint)CARRY4(uVar2,uVar6);
  param_1[10] = uVar18;
  uVar6 = param_3[0xb] + param_2[0xb];
  uVar19 = uVar2 + uVar6;
  uVar2 = (uint)CARRY4(param_3[0xb],param_2[0xb]) + (uint)CARRY4(uVar2,uVar6);
  param_1[0xb] = uVar19;
  uVar6 = param_3[0xc] + param_2[0xc];
  uVar8 = uVar2 + uVar6;
  uVar9 = (uint)CARRY4(param_3[0xc],param_2[0xc]) + (uint)CARRY4(uVar2,uVar6);
  param_1[0xc] = uVar8;
  uVar7 = param_3[0xd] + param_2[0xd];
  uVar2 = uVar9 + uVar7;
  uVar6 = uVar1 + uVar5 + 0xde933d8e;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar5) + -1 + (uint)(0x216cc271 < uVar1 + uVar5)
  ;
  uVar13 = uVar1 + uVar10 + 0x5129c970;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar10) + ((0xaed6368f < uVar1 + uVar10) - 1);
  uVar16 = uVar1 + uVar14 + 0x3bb124b7;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar14) + ((0xc44edb48 < uVar1 + uVar14) - 1);
  uVar10 = uVar1 + uVar11 + 0x8335dc17;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar11) + ((0x7cca23e8 < uVar1 + uVar11) - 1);
  uVar20 = uVar1 + uVar17 + 1;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar17) + -1 +
          (uint)(0xfffffffe < uVar1 + uVar17);
  uVar11 = uVar1 + uVar12 + 1;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar12) + -1 +
          (uint)(0xfffffffe < uVar1 + uVar12);
  uVar14 = uVar1 + uVar15 + 1;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar15) + -1 +
          (uint)(0xfffffffe < uVar1 + uVar15);
  uVar15 = uVar1 + uVar18 + 1;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar18) + -1 +
          (uint)(0xfffffffe < uVar1 + uVar18);
  uVar17 = uVar1 + uVar19 + 1;
  uVar1 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar19) + -1 +
          (uint)(0xfffffffe < uVar1 + uVar19);
  uVar12 = uVar1 + uVar8 + 1;
  uVar5 = ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar1,uVar8) + -1 + (uint)(0xfffffffe < uVar1 + uVar8)
  ;
  uVar1 = uVar5 + uVar2;
  uVar5 = (uint)CARRY4(param_3[0xd],param_2[0xd]) + (uint)CARRY4(uVar9,uVar7) +
          ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar5,uVar2) + ((0x3ffffffe < uVar1) - 1);
  uVar2 = (uint)CARRY4(uVar21 + 0x54a7bb0d,uVar5 & 0xab5844f3);
  *param_1 = uVar21 + 0x54a7bb0d + (uVar5 & 0xab5844f3);
  uVar8 = uVar2 + uVar3;
  uVar3 = (uint)CARRY4(uVar2,uVar3) + (uint)CARRY4(uVar8,uVar5 & 0x2378c292);
  uVar2 = uVar3 + uVar4;
  param_1[1] = uVar8 + (uVar5 & 0x2378c292);
  uVar3 = (uint)CARRY4(uVar3,uVar4) + (uint)CARRY4(uVar2,uVar5 & 0x8dc58f55);
  uVar4 = uVar3 + uVar6;
  uVar6 = (uint)CARRY4(uVar3,uVar6) + (uint)CARRY4(uVar4,uVar5 & 0x216cc272);
  param_1[2] = uVar2 + (uVar5 & 0x8dc58f55);
  param_1[3] = uVar4 + (uVar5 & 0x216cc272);
  uVar2 = uVar6 + uVar13;
  uVar4 = (uint)CARRY4(uVar6,uVar13) + (uint)CARRY4(uVar2,uVar5 & 0xaed63690);
  param_1[4] = uVar2 + (uVar5 & 0xaed63690);
  uVar2 = uVar4 + uVar16;
  uVar4 = (uint)CARRY4(uVar4,uVar16) + (uint)CARRY4(uVar2,uVar5 & 0xc44edb49);
  param_1[5] = uVar2 + (uVar5 & 0xc44edb49);
  uVar2 = uVar4 + uVar10;
  uVar4 = (uint)CARRY4(uVar4,uVar10) + (uint)CARRY4(uVar2,uVar5 & 0x7cca23e9);
  param_1[6] = uVar2 + (uVar5 & 0x7cca23e9);
  uVar2 = uVar4 + uVar20;
  uVar4 = (uint)CARRY4(uVar4,uVar20) + (uint)CARRY4(uVar2,uVar5);
  param_1[7] = uVar2 + uVar5;
  uVar2 = uVar4 + uVar11;
  uVar4 = (uint)CARRY4(uVar4,uVar11) + (uint)CARRY4(uVar2,uVar5);
  param_1[8] = uVar2 + uVar5;
  uVar6 = uVar4 + uVar14;
  uVar2 = (uint)CARRY4(uVar4,uVar14) + (uint)CARRY4(uVar5,uVar6);
  param_1[9] = uVar5 + uVar6;
  uVar4 = uVar2 + uVar15;
  uVar2 = (uint)CARRY4(uVar2,uVar15) + (uint)CARRY4(uVar4,uVar5);
  param_1[10] = uVar4 + uVar5;
  uVar6 = uVar2 + uVar17;
  uVar4 = (uint)CARRY4(uVar2,uVar17) + (uint)CARRY4(uVar6,uVar5);
  param_1[0xb] = uVar6 + uVar5;
  uVar2 = uVar4 + uVar12;
  param_1[0xc] = uVar2 + uVar5;
  param_1[0xd] = (uint)CARRY4(uVar4,uVar12) + (uint)CARRY4(uVar2,uVar5) + uVar1 + 0xc0000001 +
                 (uVar5 & 0x3fffffff);
  return;
}

