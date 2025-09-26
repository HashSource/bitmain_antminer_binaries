
void fe_frombytes(int *param_1,uint *param_2)

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
  
  uVar20 = param_2[4];
  uVar12 = *param_2;
  uVar15 = ((*(byte *)((int)param_2 + 0x1f) & 0x7f) << 0x10 |
            (uint)*(byte *)((int)param_2 + 0x1e) << 8 | (uint)*(byte *)((int)param_2 + 0x1d)) * 4;
  uVar14 = uVar15 + 0x1000000 >> 0x19 | (uint)(0xfeffffff < uVar15) << 7;
  uVar7 = ((uint)(byte)param_2[1] |
          (uint)*(byte *)((int)param_2 + 5) << 8 | (uint)*(byte *)((int)param_2 + 6) << 0x10) * 0x40
  ;
  uVar8 = ((uint)(byte)param_2[3] << 0x10 | (uint)*(byte *)((int)param_2 + 0xb) << 8 |
          (uint)*(byte *)((int)param_2 + 10)) * 8;
  uVar9 = ((uint)*(byte *)((int)param_2 + 0x17) |
          (uint)(byte)param_2[6] << 8 | (uint)*(byte *)((int)param_2 + 0x19) << 0x10) * 0x20;
  uVar1 = uVar7 + 0x1000000 >> 0x19 | (uint)(0xfeffffff < uVar7) << 7;
  uVar2 = uVar8 + 0x1000000 >> 0x19 | (uint)(0xfeffffff < uVar8) << 7;
  uVar3 = uVar20 + 0x1000000 >> 0x19 | (uint)(0xfeffffff < uVar20) << 7;
  uVar4 = uVar9 + 0x1000000 >> 0x19 | (uint)(0xfeffffff < uVar9) << 7;
  uVar13 = ((uint)*(byte *)((int)param_2 + 0x1a) |
           (uint)(byte)param_2[7] << 0x10 | (uint)*(byte *)((int)param_2 + 0x1b) << 8) * 0x10;
  uVar5 = ((uint)(byte)param_2[2] << 8 | (uint)*(byte *)((int)param_2 + 9) << 0x10 |
          (uint)*(byte *)((int)param_2 + 7)) * 0x20;
  uVar6 = ((uint)*(byte *)((int)param_2 + 0xe) << 8 | (uint)*(byte *)((int)param_2 + 0xf) << 0x10 |
          (uint)*(byte *)((int)param_2 + 0xd)) * 4;
  uVar16 = ((uint)(byte)param_2[5] |
           (uint)*(byte *)((int)param_2 + 0x15) << 8 | (uint)*(byte *)((int)param_2 + 0x16) << 0x10)
           * 0x80;
  uVar18 = uVar5 + uVar1;
  uVar19 = uVar2 + uVar6;
  uVar10 = uVar14 * 0x13 + uVar12;
  uVar11 = uVar3 + uVar16;
  uVar17 = uVar4 + uVar13;
  *param_1 = uVar10 - (uVar10 + 0x2000000 & 0xfc000000);
  param_1[1] = (uVar10 + 0x2000000 >> 0x1a |
               ((uint)CARRY4(uVar14 * 8,uVar14) * 2 + (uint)CARRY4(uVar14 * 9,uVar14 * 9) +
                (uint)CARRY4(uVar14 * 0x12,uVar14) + (uint)CARRY4(uVar14 * 0x13,uVar12) +
               (uint)(0xfdffffff < uVar10)) * 0x40) + (uVar7 - (uVar7 + 0x1000000 & 0xfe000000));
  param_1[5] = (uVar19 + 0x2000000 >> 0x1a |
               ((uint)CARRY4(uVar2,uVar6) + (uint)(0xfdffffff < uVar19)) * 0x40) +
               (uVar20 - (uVar20 + 0x1000000 & 0xfe000000));
  param_1[6] = uVar11 - (uVar11 + 0x2000000 & 0xfc000000);
  param_1[2] = uVar18 - (uVar18 + 0x2000000 & 0xfc000000);
  param_1[7] = (uVar9 - (uVar9 + 0x1000000 & 0xfe000000)) +
               (uVar11 + 0x2000000 >> 0x1a |
               ((uint)CARRY4(uVar3,uVar16) + (uint)(0xfdffffff < uVar11)) * 0x40);
  param_1[9] = (uVar17 + 0x2000000 >> 0x1a |
               ((uint)CARRY4(uVar4,uVar13) + (uint)(0xfdffffff < uVar17)) * 0x40) +
               (uVar15 - (uVar15 + 0x1000000 & 0xfe000000));
  param_1[3] = (uVar18 + 0x2000000 >> 0x1a |
               ((uint)CARRY4(uVar5,uVar1) + (uint)(0xfdffffff < uVar18)) * 0x40) +
               (uVar8 - (uVar8 + 0x1000000 & 0xfe000000));
  param_1[4] = uVar19 - (uVar19 + 0x2000000 & 0xfc000000);
  param_1[8] = uVar17 - (uVar17 + 0x2000000 & 0xfc000000);
  return;
}

