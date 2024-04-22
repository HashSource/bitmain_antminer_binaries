
undefined4 Camellia_Ekeygen(int param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
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
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint local_48;
  
  uVar6 = (uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18;
  uVar11 = uVar6 ^ param_2[3] | (uint)param_2[2] << 8;
  *param_3 = uVar11;
  uVar7 = (uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18;
  uVar8 = uVar7 ^ param_2[7] | (uint)param_2[6] << 8;
  param_3[1] = uVar8;
  uVar9 = (uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18;
  uVar20 = uVar9 ^ param_2[0xb] | (uint)param_2[10] << 8;
  param_3[2] = uVar20;
  uVar10 = (uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18;
  uVar2 = uVar10 ^ param_2[0xf] | (uint)param_2[0xe] << 8;
  param_3[3] = uVar2;
  if (param_1 == 0x80) {
    uVar12 = 0;
    local_48 = 0;
    uVar5 = uVar8;
    uVar16 = uVar2;
    uVar13 = uVar11;
    uVar3 = uVar20;
  }
  else {
    uVar12 = ((uint)param_2[0x11] << 0x10 | (uint)param_2[0x10] << 0x18) ^ (uint)param_2[0x13] |
             (uint)param_2[0x12] << 8;
    param_3[8] = uVar12;
    local_48 = ((uint)param_2[0x15] << 0x10 | (uint)param_2[0x14] << 0x18) ^ (uint)param_2[0x17] |
               (uint)param_2[0x16] << 8;
    param_3[9] = local_48;
    if (param_1 == 0xc0) {
      uVar3 = ~uVar12;
      uVar16 = ~local_48;
      param_3[10] = uVar3;
      param_3[0xb] = uVar16;
    }
    else {
      uVar3 = ((uint)param_2[0x19] << 0x10 | (uint)param_2[0x18] << 0x18) ^ (uint)param_2[0x1b] |
              (uint)param_2[0x1a] << 8;
      param_3[10] = uVar3;
      uVar16 = ((uint)param_2[0x1d] << 0x10 | (uint)param_2[0x1c] << 0x18) ^ (uint)param_2[0x1f] |
               (uint)param_2[0x1e] << 8;
      param_3[0xb] = uVar16;
    }
    uVar5 = local_48 ^ uVar8;
    uVar16 = uVar16 ^ uVar2;
    uVar13 = uVar12 ^ uVar11;
    uVar3 = uVar3 ^ uVar20;
  }
  iVar1 = DAT_00120de0;
  uVar13 = uVar13 ^ 0xa09e667f;
  uVar5 = uVar5 ^ 0x3bcc908b;
  uVar13 = *(uint *)(DAT_00120de0 + ((uVar13 & 0xff) + 0x100) * 4) ^
           *(uint *)(DAT_00120de0 + (uVar13 >> 0x18) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar13 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar13 << 8) >> 0x18) + 0x200) * 4);
  uVar5 = *(uint *)(DAT_00120de0 + (uVar5 & 0xff) * 4) ^
          *(uint *)(DAT_00120de0 + ((uVar5 >> 0x18) + 0x200) * 4) ^
          *(uint *)(DAT_00120de0 + (((uVar5 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(DAT_00120de0 + (((uVar5 << 8) >> 0x18) + 0x300) * 4) ^ uVar13;
  uVar3 = uVar5 ^ uVar3;
  uVar24 = uVar3 ^ 0xb67ae858;
  uVar16 = uVar5 ^ (uVar13 >> 8 | uVar13 << 0x18) ^ uVar16;
  uVar13 = uVar16 ^ 0x4caa73b2;
  uVar5 = *(uint *)(DAT_00120de0 + (((uVar24 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(DAT_00120de0 + ((uVar24 & 0xff) + 0x100) * 4) ^
          *(uint *)(DAT_00120de0 + (uVar24 >> 0x18) * 4) ^
          *(uint *)(DAT_00120de0 + (((uVar24 << 0x10) >> 0x18) + 0x300) * 4);
  uVar17 = *(uint *)(DAT_00120de0 + (uVar13 & 0xff) * 4) ^
           *(uint *)(DAT_00120de0 + ((uVar13 >> 0x18) + 0x200) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar13 << 0x10) >> 0x18) + 0x100) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar13 << 8) >> 0x18) + 0x300) * 4) ^ uVar5;
  uVar12 = uVar12 ^ uVar17;
  uVar13 = uVar12 ^ 0xc6ef372f;
  uVar17 = local_48 ^ (uVar5 >> 8 | uVar5 << 0x18) ^ uVar17;
  uVar5 = uVar17 ^ 0xe94f82be;
  uVar13 = *(uint *)(DAT_00120de0 + ((uVar13 & 0xff) + 0x100) * 4) ^
           *(uint *)(DAT_00120de0 + (uVar13 >> 0x18) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar13 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar13 << 8) >> 0x18) + 0x200) * 4);
  uVar24 = *(uint *)(DAT_00120de0 + (uVar5 & 0xff) * 4) ^
           *(uint *)(DAT_00120de0 + ((uVar5 >> 0x18) + 0x200) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar5 << 0x10) >> 0x18) + 0x100) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar5 << 8) >> 0x18) + 0x300) * 4) ^ uVar13;
  uVar5 = uVar3 ^ uVar20 ^ uVar24;
  uVar24 = uVar24 ^ uVar16 ^ uVar2 ^ (uVar13 >> 8 | uVar13 << 0x18);
  uVar13 = uVar5 ^ 0x54ff53a5;
  uVar16 = uVar24 ^ 0xf1d36f1c;
  uVar13 = *(uint *)(DAT_00120de0 + ((uVar13 & 0xff) + 0x100) * 4) ^
           *(uint *)(DAT_00120de0 + (uVar13 >> 0x18) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar13 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar13 << 8) >> 0x18) + 0x200) * 4);
  uVar16 = *(uint *)(DAT_00120de0 + ((uVar16 >> 0x18) + 0x200) * 4) ^
           *(uint *)(DAT_00120de0 + (uVar16 & 0xff) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar16 << 0x10) >> 0x18) + 0x100) * 4) ^
           *(uint *)(DAT_00120de0 + (((uVar16 << 8) >> 0x18) + 0x300) * 4) ^ uVar13;
  uVar12 = uVar16 ^ uVar12;
  uVar16 = uVar17 ^ (uVar13 >> 8 | uVar13 << 0x18) ^ uVar16;
  if (param_1 == 0x80) {
    uVar13 = uVar16 >> 0x11 | uVar12 << 0xf;
    param_3[0xc] = uVar13;
    uVar14 = uVar12 >> 0x11 | uVar24 << 0xf;
    uVar17 = uVar24 >> 0x11 | uVar5 << 0xf;
    uVar3 = uVar5 >> 0x11 | uVar16 << 0xf;
    uVar18 = uVar7 >> 0x11 | uVar11 << 0xf;
    uVar11 = uVar3 << 0xf;
    uVar15 = (uVar5 << 0xf) >> 0x11 | uVar11;
    param_3[4] = uVar12;
    param_3[0xb] = uVar6 >> 0x11 | uVar2 << 0xf;
    param_3[9] = uVar9 >> 0x11 | uVar8 << 0xf;
    uVar2 = uVar17 << 0xf;
    uVar25 = (uVar24 << 0xf) >> 0x11 | uVar2;
    param_3[10] = uVar10 >> 0x11 | uVar20 << 0xf;
    uVar13 = uVar13 << 0xf;
    uVar10 = (uVar16 << 0xf) >> 0x11 | uVar13;
    param_3[5] = uVar16;
    uVar6 = uVar14 << 0xf;
    uVar16 = (uVar12 << 0xf) >> 0x11 | uVar6;
    param_3[6] = uVar5;
    param_3[0x14] = param_3[9] >> 2 | (uVar7 >> 0x11) << 0x1e;
    param_3[0x17] = uVar18 >> 2 | param_3[0xb] << 0x1e;
    param_3[7] = uVar24;
    param_3[0x16] = param_3[0xb] >> 2 | param_3[10] << 0x1e;
    param_3[0x15] = param_3[10] >> 2 | param_3[9] << 0x1e;
    uVar7 = uVar16 << 0xf;
    param_3[0xe] = uVar17;
    param_3[0xf] = uVar14;
    uVar8 = uVar10 << 0xf;
    uVar11 = uVar11 >> 0x11 | uVar8;
    uVar9 = uVar25 << 0xf;
    param_3[0xd] = uVar3;
    param_3[0x12] = uVar25;
    param_3[0x10] = uVar10;
    uVar10 = uVar15 << 0xf;
    uVar20 = uVar2 >> 0x11 | uVar10;
    param_3[0x13] = uVar16;
    param_3[0x18] = uVar11;
    param_3[0x1b] = param_3[0x14] >> 0x11 | param_3[0x17] << 0xf;
    uVar11 = uVar11 << 0xf;
    uVar10 = uVar10 >> 0x11 | uVar11;
    param_3[0x19] = uVar20;
    param_3[0x1c] = uVar10;
    param_3[0x11] = uVar15;
    param_3[0x1a] = param_3[0x17] >> 0x11 | param_3[0x16] << 0xf;
    param_3[8] = uVar18;
    uVar2 = (uVar13 >> 0x11 | uVar7) << 0xf;
    uVar8 = uVar8 >> 0x11 | uVar2;
    param_3[0x1f] = uVar8;
    uVar6 = (uVar6 >> 0x11 | uVar9) << 0xf;
    uVar5 = uVar7 >> 0x11 | uVar6;
    uVar20 = uVar20 << 0xf;
    uVar9 = uVar9 >> 0x11 | uVar20;
    uVar7 = uVar5 << 2;
    uVar12 = uVar2 >> 0x1e | uVar7;
    uVar2 = uVar9 << 2;
    uVar16 = uVar6 >> 0x1e | uVar2;
    param_3[0x1d] = uVar9;
    uVar13 = param_3[0x14] & 0x1ffff;
    param_3[0x1e] = uVar5;
    param_3[0x20] = param_3[0x15] & 0x1ffff | param_3[0x15] & 0xfffe0000;
    uVar10 = uVar10 << 2;
    uVar3 = uVar20 >> 0x1e | uVar10;
    param_3[0x28] = uVar16;
    uVar8 = uVar8 << 2;
    uVar6 = uVar11 >> 0x1e | uVar8;
    param_3[0x2b] = uVar3;
    uVar5 = uVar13 | param_3[0x1b] << 0x11;
    uVar24 = param_3[0x1b] >> 0xf;
    uVar20 = uVar24 | param_3[0x1a] << 0x11;
    uVar9 = param_3[0x1a] >> 0xf;
    param_3[0x2a] = uVar6;
    uVar25 = uVar9 | param_3[0x16] & 0xfffe0000;
    param_3[0x29] = uVar12;
    uVar17 = uVar25 >> 0xf;
    param_3[0x30] = uVar7 >> 0xf | uVar16 << 0x11;
    uVar7 = param_3[0x20] >> 0xf | uVar13 << 0x11;
    param_3[0x33] = uVar2 >> 0xf | uVar3 << 0x11;
    param_3[0x32] = uVar10 >> 0xf | uVar6 << 0x11;
    uVar2 = uVar5 >> 0xf;
    uVar10 = uVar20 >> 0xf;
    uVar11 = uVar17 | param_3[0x20] << 0x11;
    param_3[0x31] = uVar8 >> 0xf | uVar12 << 0x11;
    uVar6 = uVar2 | uVar24 << 0x11;
    uVar8 = uVar10 | uVar9 << 0x11;
    param_3[0x21] = uVar25;
    uVar4 = 3;
    param_3[0x22] = uVar20;
    param_3[0x23] = uVar5;
    param_3[0x24] = uVar11;
    param_3[0x25] = uVar8;
    param_3[0x26] = uVar6;
    param_3[0x27] = uVar7;
    param_3[0x2c] = uVar8 >> 0xf | uVar17 << 0x11;
    param_3[0x2f] = uVar11 >> 0xf | (param_3[0x20] >> 0xf) << 0x11;
    param_3[0x2e] = uVar7 >> 0xf | uVar2 << 0x11;
    param_3[0x2d] = uVar6 >> 0xf | uVar10 << 0x11;
  }
  else {
    uVar15 = param_3[8];
    uVar18 = param_3[9];
    uVar3 = uVar12 ^ uVar15 ^ 0x10e527fa;
    uVar13 = uVar16 ^ uVar18 ^ 0xde682d1d;
    uVar17 = param_3[8];
    uVar25 = *(uint *)(DAT_00120de0 + ((uVar3 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_00120de0 + (uVar3 >> 0x18) * 4) ^
             *(uint *)(DAT_00120de0 + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_00120de0 + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
    uVar3 = *(uint *)(DAT_00120de0 + (((uVar13 << 8) >> 0x18) + 0x300) * 4) ^
            *(uint *)(DAT_00120de0 + ((uVar13 >> 0x18) + 0x200) * 4) ^
            *(uint *)(DAT_00120de0 + (uVar13 & 0xff) * 4) ^
            *(uint *)(DAT_00120de0 + (((uVar13 << 0x10) >> 0x18) + 0x100) * 4) ^ uVar25;
    uVar19 = uVar5 ^ param_3[10] ^ uVar3;
    param_3[8] = uVar17 << 0xf | param_3[9] >> 0x11;
    uVar22 = uVar19 ^ 0xb05688c2;
    uVar3 = uVar24 ^ param_3[0xb] ^ (uVar25 >> 8 | uVar25 << 0x18) ^ uVar3;
    uVar13 = uVar3 ^ 0xb3e6c1fd;
    uVar25 = uVar17 >> 0x11 | param_3[0xb] << 0xf;
    param_3[7] = uVar3;
    param_3[9] = param_3[9] << 0xf | param_3[10] >> 0x11;
    uVar23 = *(uint *)(iVar1 + ((uVar22 & 0xff) + 0x100) * 4);
    uVar21 = *(uint *)(iVar1 + ((uVar13 >> 0x18) + 0x200) * 4);
    uVar14 = *(uint *)(iVar1 + (uVar13 & 0xff) * 4);
    param_3[10] = param_3[10] << 0xf | param_3[0xb] >> 0x11;
    uVar26 = *(uint *)(iVar1 + (((uVar13 << 0x10) >> 0x18) + 0x100) * 4);
    uVar17 = *(uint *)(iVar1 + (((uVar13 << 8) >> 0x18) + 0x300) * 4);
    uVar13 = uVar23 ^ *(uint *)(iVar1 + (uVar22 >> 0x18) * 4) ^
             *(uint *)(iVar1 + (((uVar22 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(iVar1 + (((uVar22 << 8) >> 0x18) + 0x200) * 4);
    param_3[6] = uVar19;
    param_3[0x18] = uVar9 >> 0x13 | uVar8 << 0xd;
    uVar8 = uVar3 >> 2 | uVar19 << 0x1e;
    param_3[0x1b] = uVar7 >> 0x13 | uVar11 << 0xd;
    param_3[0x1a] = uVar6 >> 0x13 | uVar2 << 0xd;
    uVar2 = uVar21 ^ uVar14 ^ uVar26 ^ uVar17 ^ uVar13;
    uVar7 = uVar16 ^ uVar18 ^ (uVar13 >> 8 | uVar13 << 0x18) ^ uVar2;
    param_3[0x19] = uVar10 >> 0x13 | uVar20 << 0xd;
    uVar2 = uVar2 ^ uVar12 ^ uVar15;
    uVar13 = uVar7 >> 2 | uVar2 << 0x1e;
    param_3[4] = uVar2;
    uVar15 = param_3[9] >> 0x11;
    uVar6 = uVar2 >> 2 | uVar3 << 0x1e;
    uVar17 = param_3[10] >> 0x11;
    uVar9 = uVar19 >> 2 | uVar7 << 0x1e;
    uVar18 = uVar15 | param_3[8] << 0xf;
    param_3[0x13] = param_3[8] >> 0x11 | uVar25 << 0xf;
    param_3[0x12] = (param_3[0xb] << 0xf) >> 0x11 | param_3[10] << 0xf;
    uVar14 = uVar17 | param_3[9] << 0xf;
    param_3[0x20] = param_3[0x19] >> 0x11 | param_3[0x18] << 0xf;
    param_3[0x23] = param_3[0x18] >> 0x11 | param_3[0x1b] << 0xf;
    param_3[5] = uVar7;
    uVar11 = uVar6 >> 2;
    param_3[0x15] = uVar9;
    uVar20 = uVar11 | (uVar3 >> 2) << 0x1e;
    param_3[0x14] = uVar13;
    param_3[0x17] = uVar6;
    param_3[0x16] = uVar8;
    param_3[0xc] = uVar16 >> 0x11 | uVar12 << 0xf;
    param_3[0x2a] = uVar20;
    param_3[0xf] = uVar12 >> 0x11 | uVar24 << 0xf;
    param_3[0xe] = uVar24 >> 0x11 | uVar5 << 0xf;
    param_3[0xd] = uVar5 >> 0x11 | uVar16 << 0xf;
    uVar8 = uVar8 >> 2;
    param_3[0x22] = param_3[0x1b] >> 0x11 | param_3[0x1a] << 0xf;
    uVar6 = uVar8 | (uVar19 >> 2) << 0x1e;
    uVar9 = uVar9 >> 2;
    uVar10 = uVar9 | (uVar7 >> 2) << 0x1e;
    uVar13 = uVar13 >> 2;
    param_3[0x29] = uVar6;
    uVar5 = uVar13 | (uVar2 >> 2) << 0x1e;
    param_3[0x28] = uVar10;
    param_3[0x21] = param_3[0x1a] >> 0x11 | param_3[0x19] << 0xf;
    uVar2 = param_3[0x13];
    param_3[0x2b] = uVar5;
    param_3[0x40] = uVar20 >> 0xd | uVar8 << 0x13;
    uVar7 = param_3[0x12];
    param_3[0x42] = uVar10 >> 0xd | uVar13 << 0x13;
    param_3[0x41] = uVar5 >> 0xd | uVar11 << 0x13;
    uVar10 = param_3[0xc] >> 2;
    param_3[0x43] = uVar6 >> 0xd | uVar9 << 0x13;
    param_3[0x2f] = param_3[0x20] >> 0xf | param_3[0x23] << 0x11;
    uVar11 = param_3[0xd] >> 2 | param_3[0xc] << 0x1e;
    uVar20 = param_3[0xf] >> 2;
    uVar9 = uVar10 | param_3[0xf] << 0x1e;
    uVar5 = uVar20 | param_3[0xe] << 0x1e;
    uVar6 = param_3[0xe] >> 2;
    uVar8 = uVar6 | param_3[0xd] << 0x1e;
    param_3[0x2e] = param_3[0x23] >> 0xf | param_3[0x22] << 0x11;
    param_3[0x11] = uVar14;
    param_3[0x25] = uVar7 >> 2 | uVar17 << 0x1e;
    param_3[0x24] = uVar14 >> 2 | uVar15 << 0x1e;
    param_3[0x27] = uVar18 >> 2 | uVar2 << 0x1e;
    param_3[0xb] = uVar25;
    param_3[0x26] = uVar2 >> 2 | uVar7 << 0x1e;
    param_3[0x37] = uVar17 & 3 | uVar17 & 0xfffffffc | param_3[9] << 0xf;
    param_3[0x35] = uVar2;
    param_3[0x2d] = param_3[0x22] >> 0xf | param_3[0x21] << 0x11;
    param_3[0x3b] = uVar8 >> 0xf | (param_3[0xd] >> 2) << 0x11;
    param_3[0x36] = uVar15 & 3 | uVar15 & 0xfffffffc | param_3[8] << 0xf;
    param_3[0x10] = uVar18;
    param_3[0x34] = uVar7;
    uVar2 = param_3[0x21] >> 0xf | param_3[0x20] << 0x11;
    param_3[0x1d] = uVar8;
    param_3[0x2c] = uVar2;
    param_3[0x30] = uVar8;
    uVar4 = 4;
    param_3[0x1c] = uVar11;
    param_3[0x1e] = uVar5;
    param_3[0x1f] = uVar9;
    param_3[0x31] = uVar5;
    param_3[0x32] = uVar9;
    param_3[0x33] = uVar11;
    param_3[0x38] = uVar5 >> 0xf | uVar6 << 0x11;
    param_3[0x3a] = uVar11 >> 0xf | uVar10 << 0x11;
    param_3[0x39] = uVar9 >> 0xf | uVar20 << 0x11;
    param_3[0x3c] = param_3[0x2e] >> 0x1e | param_3[0x2d] << 2;
    param_3[0x3f] = param_3[0x2d] >> 0x1e | uVar2 << 2;
    param_3[0x3e] = (param_3[0x20] << 0x11) >> 0x1e | param_3[0x2f] << 2;
    param_3[0x3d] = param_3[0x2f] >> 0x1e | param_3[0x2e] << 2;
  }
  return uVar4;
}

