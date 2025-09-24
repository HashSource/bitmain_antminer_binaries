
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
  
  memset(param_1,0,0x1a8);
  *(code **)((int)param_1 + 0x170) = param_3;
  *(undefined4 *)((int)param_1 + 0x174) = param_2;
  (*param_3)((int)param_1 + 0x50,(int)param_1 + 0x50,param_2);
  bVar1 = *(byte *)((int)param_1 + 0x5b);
  uVar6 = (uint)*(byte *)((int)param_1 + 0x51) << 0x10 |
          (uint)*(byte *)((int)param_1 + 0x50) << 0x18 | (uint)*(byte *)((int)param_1 + 0x53) |
          (uint)*(byte *)((int)param_1 + 0x52) << 8;
  uVar2 = (uint)*(byte *)((int)param_1 + 0x5f);
  uVar11 = (uint)*(byte *)((int)param_1 + 0x59) << 0x10 |
           (uint)*(byte *)((int)param_1 + 0x58) << 0x18 | (uint)bVar1 |
           (uint)*(byte *)((int)param_1 + 0x5a) << 8;
  uVar15 = (uint)*(byte *)((int)param_1 + 0x5d) << 0x10 |
           (uint)*(byte *)((int)param_1 + 0x5c) << 0x18 | uVar2 |
           (uint)*(byte *)((int)param_1 + 0x5e) << 8;
  uVar3 = (uint)*(byte *)((int)param_1 + 0x55) << 0x10 |
          (uint)*(byte *)((int)param_1 + 0x54) << 0x18 | (uint)*(byte *)((int)param_1 + 0x57) |
          (uint)*(byte *)((int)param_1 + 0x56) << 8;
  *(uint *)((int)param_1 + 0x58) = uVar15;
  *(uint *)((int)param_1 + 0x5c) = uVar11;
  uVar8 = (uint)((*(byte *)((int)param_1 + 0x53) & 1) != 0) << 0x1f | uVar3 >> 1;
  uVar4 = (uint)((bVar1 & 1) != 0) << 0x1f | uVar15 >> 1;
  uVar7 = -(uVar2 & 1) & 0xe1000000 ^ uVar6 >> 1;
  uVar16 = (uint)*(byte *)((int)param_1 + 0x57) << 0x1f | uVar11 >> 1;
  *(uint *)((int)param_1 + 0xe8) = uVar15;
  *(uint *)((int)param_1 + 0xec) = uVar11;
  uVar14 = (uint)((bVar1 & 2) != 0) << 0x1f | uVar4 >> 1;
  uVar5 = (uint)((uVar7 & 1) != 0) << 0x1f | uVar8 >> 1;
  uVar9 = -((uVar2 & 2) >> 1) & 0xe1000000 ^ uVar7 >> 1;
  uVar17 = (uVar3 >> 1) << 0x1f | uVar16 >> 1;
  *(uint *)((int)param_1 + 0x50) = uVar3;
  *(uint *)((int)param_1 + 0x54) = uVar6;
  uVar19 = (uint)((uVar9 & 1) != 0) << 0x1f | uVar5 >> 1;
  uVar18 = (uint)((bVar1 & 4) != 0) << 0x1f | uVar14 >> 1;
  uVar20 = uVar9 >> 1 ^ -((uVar2 & 4) >> 2) & 0xe1000000;
  uVar21 = uVar17 >> 1 | (uVar8 >> 1) << 0x1f;
  uVar2 = uVar5 ^ uVar19;
  uVar12 = uVar9 ^ uVar20;
  uVar13 = uVar21 ^ uVar17;
  uVar10 = uVar18 ^ uVar14;
  *(uint *)((int)param_1 + 0xf0) = uVar3 ^ uVar19;
  *(uint *)((int)param_1 + 0xf4) = uVar6 ^ uVar20;
  *(uint *)((int)param_1 + 0xe0) = uVar3;
  *(uint *)((int)param_1 + 0xe4) = uVar6;
  *(uint *)((int)param_1 + 0xa8) = uVar4;
  *(uint *)((int)param_1 + 0xac) = uVar16;
  *(uint *)((int)param_1 + 0xa0) = uVar8;
  *(uint *)((int)param_1 + 0xa4) = uVar7;
  *(uint *)((int)param_1 + 0x88) = uVar14;
  *(uint *)((int)param_1 + 0x8c) = uVar17;
  *(uint *)((int)param_1 + 0x80) = uVar5;
  *(uint *)((int)param_1 + 0x84) = uVar9;
  *(uint *)((int)param_1 + 0x70) = uVar19;
  *(uint *)((int)param_1 + 0x74) = uVar20;
  *(undefined4 *)((int)param_1 + 0x60) = 0;
  *(undefined4 *)((int)param_1 + 100) = 0;
  *(undefined4 *)((int)param_1 + 0x68) = 0;
  *(undefined4 *)((int)param_1 + 0x6c) = 0;
  *(uint *)((int)param_1 + 0x78) = uVar18;
  *(uint *)((int)param_1 + 0x7c) = uVar21;
  *(uint *)((int)param_1 + 0x90) = uVar2;
  *(uint *)((int)param_1 + 0x94) = uVar12;
  *(uint *)((int)param_1 + 0xb0) = uVar8 ^ uVar19;
  *(uint *)((int)param_1 + 0xb4) = uVar7 ^ uVar20;
  *(uint *)((int)param_1 + 0xf8) = uVar18 ^ uVar15;
  *(uint *)((int)param_1 + 0xfc) = uVar21 ^ uVar11;
  *(uint *)((int)param_1 + 0xb8) = uVar18 ^ uVar4;
  *(uint *)((int)param_1 + 0xbc) = uVar21 ^ uVar16;
  *(uint *)((int)param_1 + 0x98) = uVar10;
  *(uint *)((int)param_1 + 0x9c) = uVar13;
  *(uint *)((int)param_1 + 0xc0) = uVar5 ^ uVar8;
  *(uint *)((int)param_1 + 0xc4) = uVar9 ^ uVar7;
  *(uint *)((int)param_1 + 200) = uVar4 ^ uVar14;
  *(uint *)((int)param_1 + 0xcc) = uVar16 ^ uVar17;
  *(uint *)((int)param_1 + 0xd0) = uVar2 ^ uVar8;
  *(uint *)((int)param_1 + 0xd4) = uVar12 ^ uVar7;
  *(uint *)((int)param_1 + 0xd8) = uVar4 ^ uVar10;
  *(uint *)((int)param_1 + 0xdc) = uVar16 ^ uVar13;
  *(uint *)((int)param_1 + 0x100) = uVar3 ^ uVar5;
  *(uint *)((int)param_1 + 0x104) = uVar6 ^ uVar9;
  *(uint *)((int)param_1 + 0x108) = uVar15 ^ uVar14;
  *(uint *)((int)param_1 + 0x10c) = uVar11 ^ uVar17;
  *(uint *)((int)param_1 + 0x110) = uVar2 ^ uVar3;
  *(uint *)((int)param_1 + 0x114) = uVar12 ^ uVar6;
  *(uint *)((int)param_1 + 0x118) = uVar15 ^ uVar10;
  *(uint *)((int)param_1 + 0x11c) = uVar11 ^ uVar13;
  *(uint *)((int)param_1 + 0x120) = uVar3 ^ uVar8;
  *(uint *)((int)param_1 + 0x124) = uVar6 ^ uVar7;
  *(uint *)((int)param_1 + 0x128) = uVar15 ^ uVar4;
  *(uint *)((int)param_1 + 300) = uVar11 ^ uVar16;
  *(uint *)((int)param_1 + 0x130) = uVar3 ^ uVar8 ^ uVar19;
  *(uint *)((int)param_1 + 0x134) = uVar6 ^ uVar7 ^ uVar20;
  *(uint *)((int)param_1 + 0x138) = uVar15 ^ uVar18 ^ uVar4;
  *(uint *)((int)param_1 + 0x13c) = uVar11 ^ uVar21 ^ uVar16;
  *(uint *)((int)param_1 + 0x140) = uVar3 ^ uVar5 ^ uVar8;
  *(uint *)((int)param_1 + 0x144) = uVar6 ^ uVar9 ^ uVar7;
  *(uint *)((int)param_1 + 0x148) = uVar15 ^ uVar4 ^ uVar14;
  *(uint *)((int)param_1 + 0x14c) = uVar11 ^ uVar16 ^ uVar17;
  *(uint *)((int)param_1 + 0x150) = uVar3 ^ uVar2 ^ uVar8;
  *(uint *)((int)param_1 + 0x154) = uVar6 ^ uVar12 ^ uVar7;
  *(uint *)((int)param_1 + 0x158) = uVar15 ^ uVar4 ^ uVar10;
  *(uint *)((int)param_1 + 0x15c) = uVar11 ^ uVar16 ^ uVar13;
  return;
}

