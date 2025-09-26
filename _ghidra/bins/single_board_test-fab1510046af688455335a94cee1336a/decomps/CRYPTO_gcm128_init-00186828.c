
void CRYPTO_gcm128_init(void *param_1,undefined4 param_2,code *param_3)

{
  byte bVar1;
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
  
  memset(param_1,0,0x178);
  *(code **)((int)param_1 + 0x170) = param_3;
  *(undefined4 *)((int)param_1 + 0x174) = param_2;
  (*param_3)((int)param_1 + 0x50,(int)param_1 + 0x50,param_2);
  bVar1 = *(byte *)((int)param_1 + 0x5b);
  uVar8 = (uint)*(byte *)((int)param_1 + 0x51) << 0x10 |
          (uint)*(byte *)((int)param_1 + 0x50) << 0x18 | (uint)*(byte *)((int)param_1 + 0x53) |
          (uint)*(byte *)((int)param_1 + 0x52) << 8;
  uVar10 = (uint)*(byte *)((int)param_1 + 0x59) << 0x10 |
           (uint)*(byte *)((int)param_1 + 0x58) << 0x18 | (uint)bVar1 |
           (uint)*(byte *)((int)param_1 + 0x5a) << 8;
  uVar2 = (uint)*(byte *)((int)param_1 + 0x5f);
  uVar13 = (uint)*(byte *)((int)param_1 + 0x55) << 0x10 |
           (uint)*(byte *)((int)param_1 + 0x54) << 0x18 | (uint)*(byte *)((int)param_1 + 0x57) |
           (uint)*(byte *)((int)param_1 + 0x56) << 8;
  uVar3 = uVar2 | (uint)*(byte *)((int)param_1 + 0x5d) << 0x10 |
                  (uint)*(byte *)((int)param_1 + 0x5c) << 0x18 |
          (uint)*(byte *)((int)param_1 + 0x5e) << 8;
  *(uint *)((int)param_1 + 0x58) = uVar3;
  *(uint *)((int)param_1 + 0x5c) = uVar10;
  uVar14 = (uint)((*(byte *)((int)param_1 + 0x53) & 1) != 0) << 0x1f | uVar13 >> 1;
  uVar19 = -(uVar2 & 1) & 0xe1000000 ^ uVar8 >> 1;
  uVar11 = (uint)((bVar1 & 1) != 0) << 0x1f | uVar3 >> 1;
  uVar4 = uVar10 >> 1 | (uint)*(byte *)((int)param_1 + 0x57) << 0x1f;
  uVar15 = (uint)((bVar1 & 2) != 0) << 0x1f | uVar11 >> 1;
  uVar20 = (uVar13 >> 1) << 0x1f | uVar4 >> 1;
  *(uint *)((int)param_1 + 0xe8) = uVar3;
  *(uint *)((int)param_1 + 0xec) = uVar10;
  uVar18 = (uint)((uVar19 & 1) != 0) << 0x1f | uVar14 >> 1;
  uVar21 = uVar19 >> 1 ^ -((uVar2 & 2) >> 1) & 0xe1000000;
  *(uint *)((int)param_1 + 0x80) = uVar18;
  *(uint *)((int)param_1 + 0x84) = uVar21;
  *(uint *)((int)param_1 + 0x50) = uVar13;
  *(uint *)((int)param_1 + 0x54) = uVar8;
  uVar16 = (uint)((uVar21 & 1) != 0) << 0x1f | uVar18 >> 1;
  uVar17 = uVar21 >> 1 ^ -((uVar2 & 4) >> 2) & 0xe1000000;
  uVar6 = (uint)((bVar1 & 4) != 0) << 0x1f | uVar15 >> 1;
  uVar2 = uVar16 ^ uVar18;
  uVar12 = uVar20 >> 1 | (uVar14 >> 1) << 0x1f;
  uVar5 = uVar17 ^ uVar21;
  *(uint *)((int)param_1 + 0x70) = uVar16;
  *(uint *)((int)param_1 + 0x74) = uVar17;
  uVar7 = uVar6 ^ uVar15;
  uVar9 = uVar12 ^ uVar20;
  *(uint *)((int)param_1 + 0xf0) = uVar16 ^ uVar13;
  *(uint *)((int)param_1 + 0xf4) = uVar17 ^ uVar8;
  *(undefined4 *)((int)param_1 + 0x60) = 0;
  *(undefined4 *)((int)param_1 + 100) = 0;
  *(uint *)((int)param_1 + 0xa0) = uVar14;
  *(uint *)((int)param_1 + 0xa4) = uVar19;
  *(undefined4 *)((int)param_1 + 0x68) = 0;
  *(undefined4 *)((int)param_1 + 0x6c) = 0;
  *(uint *)((int)param_1 + 0xa8) = uVar11;
  *(uint *)((int)param_1 + 0xac) = uVar4;
  *(uint *)((int)param_1 + 0xe0) = uVar13;
  *(uint *)((int)param_1 + 0xe4) = uVar8;
  *(uint *)((int)param_1 + 0x88) = uVar15;
  *(uint *)((int)param_1 + 0x8c) = uVar20;
  *(uint *)((int)param_1 + 0x78) = uVar6;
  *(uint *)((int)param_1 + 0x7c) = uVar12;
  *(uint *)((int)param_1 + 0x90) = uVar2;
  *(uint *)((int)param_1 + 0x94) = uVar5;
  *(uint *)((int)param_1 + 0xb0) = uVar16 ^ uVar14;
  *(uint *)((int)param_1 + 0xb4) = uVar17 ^ uVar19;
  *(uint *)((int)param_1 + 0xb8) = uVar6 ^ uVar11;
  *(uint *)((int)param_1 + 0xbc) = uVar12 ^ uVar4;
  *(uint *)((int)param_1 + 0xf8) = uVar6 ^ uVar3;
  *(uint *)((int)param_1 + 0xfc) = uVar12 ^ uVar10;
  *(uint *)((int)param_1 + 0x98) = uVar7;
  *(uint *)((int)param_1 + 0x9c) = uVar9;
  *(uint *)((int)param_1 + 0xc0) = uVar18 ^ uVar14;
  *(uint *)((int)param_1 + 0xc4) = uVar21 ^ uVar19;
  *(uint *)((int)param_1 + 0xd0) = uVar2 ^ uVar14;
  *(uint *)((int)param_1 + 0xd4) = uVar5 ^ uVar19;
  *(uint *)((int)param_1 + 200) = uVar15 ^ uVar11;
  *(uint *)((int)param_1 + 0xcc) = uVar20 ^ uVar4;
  *(uint *)((int)param_1 + 0x100) = uVar18 ^ uVar13;
  *(uint *)((int)param_1 + 0x104) = uVar21 ^ uVar8;
  *(uint *)((int)param_1 + 0xd8) = uVar7 ^ uVar11;
  *(uint *)((int)param_1 + 0xdc) = uVar9 ^ uVar4;
  *(uint *)((int)param_1 + 0x110) = uVar2 ^ uVar13;
  *(uint *)((int)param_1 + 0x114) = uVar5 ^ uVar8;
  *(uint *)((int)param_1 + 0x120) = uVar14 ^ uVar13;
  *(uint *)((int)param_1 + 0x124) = uVar19 ^ uVar8;
  *(uint *)((int)param_1 + 0x130) = uVar16 ^ uVar14 ^ uVar13;
  *(uint *)((int)param_1 + 0x134) = uVar17 ^ uVar19 ^ uVar8;
  *(uint *)((int)param_1 + 0x140) = uVar18 ^ uVar14 ^ uVar13;
  *(uint *)((int)param_1 + 0x144) = uVar21 ^ uVar19 ^ uVar8;
  *(uint *)((int)param_1 + 0x108) = uVar15 ^ uVar3;
  *(uint *)((int)param_1 + 0x10c) = uVar20 ^ uVar10;
  *(uint *)((int)param_1 + 0x150) = uVar2 ^ uVar14 ^ uVar13;
  *(uint *)((int)param_1 + 0x154) = uVar5 ^ uVar19 ^ uVar8;
  *(uint *)((int)param_1 + 0x118) = uVar7 ^ uVar3;
  *(uint *)((int)param_1 + 0x11c) = uVar9 ^ uVar10;
  *(uint *)((int)param_1 + 0x128) = uVar11 ^ uVar3;
  *(uint *)((int)param_1 + 300) = uVar4 ^ uVar10;
  *(uint *)((int)param_1 + 0x138) = uVar6 ^ uVar11 ^ uVar3;
  *(uint *)((int)param_1 + 0x13c) = uVar12 ^ uVar4 ^ uVar10;
  *(uint *)((int)param_1 + 0x148) = uVar15 ^ uVar11 ^ uVar3;
  *(uint *)((int)param_1 + 0x14c) = uVar20 ^ uVar4 ^ uVar10;
  *(uint *)((int)param_1 + 0x158) = uVar7 ^ uVar11 ^ uVar3;
  *(uint *)((int)param_1 + 0x15c) = uVar9 ^ uVar4 ^ uVar10;
  return;
}

