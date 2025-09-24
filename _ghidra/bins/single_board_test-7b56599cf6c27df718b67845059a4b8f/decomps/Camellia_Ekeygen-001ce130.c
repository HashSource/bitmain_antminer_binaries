
undefined4 Camellia_Ekeygen(int param_1,byte *param_2,uint *param_3)

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
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  
  uVar1 = (uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18;
  uVar2 = uVar1 ^ param_2[3] | (uint)param_2[2] << 8;
  *param_3 = uVar2;
  uVar3 = (uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18;
  uVar4 = uVar3 ^ param_2[7] | (uint)param_2[6] << 8;
  param_3[1] = uVar4;
  uVar5 = (uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18;
  uVar6 = uVar5 ^ param_2[0xb] | (uint)param_2[10] << 8;
  param_3[2] = uVar6;
  uVar7 = (uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18;
  uVar8 = uVar7 ^ param_2[0xf] | (uint)param_2[0xe] << 8;
  param_3[3] = uVar8;
  if (param_1 == 0x80) {
    uVar14 = 0;
    uVar9 = 0;
    uVar10 = uVar4;
    uVar12 = uVar2;
    uVar15 = uVar6;
    uVar11 = uVar8;
  }
  else {
    uVar14 = (uint)param_2[0x13] ^ ((uint)param_2[0x11] << 0x10 | (uint)param_2[0x10] << 0x18) |
             (uint)param_2[0x12] << 8;
    param_3[8] = uVar14;
    uVar9 = (uint)param_2[0x17] ^ ((uint)param_2[0x15] << 0x10 | (uint)param_2[0x14] << 0x18) |
            (uint)param_2[0x16] << 8;
    param_3[9] = uVar9;
    if (param_1 == 0xc0) {
      uVar15 = ~uVar14;
      uVar11 = ~uVar9;
      param_3[10] = uVar15;
      param_3[0xb] = uVar11;
    }
    else {
      uVar15 = (uint)param_2[0x1b] ^ ((uint)param_2[0x19] << 0x10 | (uint)param_2[0x18] << 0x18) |
               (uint)param_2[0x1a] << 8;
      param_3[10] = uVar15;
      uVar11 = ((uint)param_2[0x1d] << 0x10 | (uint)param_2[0x1c] << 0x18) ^ (uint)param_2[0x1f] |
               (uint)param_2[0x1e] << 8;
      param_3[0xb] = uVar11;
    }
    uVar10 = uVar4 ^ uVar9;
    uVar12 = uVar14 ^ uVar2;
    uVar15 = uVar15 ^ uVar6;
    uVar11 = uVar11 ^ uVar8;
  }
  uVar10 = uVar10 ^ 0x3bcc908b;
  uVar12 = uVar12 ^ 0xa09e667f;
  uVar12 = *(uint *)(&Camellia_SBOX + ((uVar12 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar12 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x200) * 4);
  uVar10 = uVar12 ^ *(uint *)(&Camellia_SBOX + (uVar10 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar10 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x300) * 4);
  uVar15 = uVar15 ^ uVar10;
  uVar18 = uVar15 ^ 0xb67ae858;
  uVar11 = uVar10 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar11;
  uVar10 = uVar11 ^ 0x4caa73b2;
  uVar12 = *(uint *)(&Camellia_SBOX + ((uVar18 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar18 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar18 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar18 << 8) >> 0x18) + 0x200) * 4);
  uVar10 = uVar12 ^ *(uint *)(&Camellia_SBOX + (uVar10 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar10 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x300) * 4);
  uVar14 = uVar10 ^ uVar14;
  uVar18 = uVar14 ^ 0xc6ef372f;
  uVar10 = uVar9 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar10;
  uVar12 = uVar10 ^ 0xe94f82be;
  uVar19 = *(uint *)(&Camellia_SBOX + ((uVar18 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar18 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar18 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar18 << 8) >> 0x18) + 0x200) * 4);
  uVar18 = uVar19 ^ *(uint *)(&Camellia_SBOX + (uVar12 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar12 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x300) * 4);
  uVar12 = uVar6 ^ uVar15 ^ uVar18;
  uVar9 = uVar12 ^ 0x54ff53a5;
  uVar18 = uVar8 ^ uVar11 ^ (uVar19 >> 8 | uVar19 << 0x18) ^ uVar18;
  uVar15 = uVar18 ^ 0xf1d36f1c;
  uVar11 = *(uint *)(&Camellia_SBOX + ((uVar9 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar9 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x200) * 4);
  uVar15 = uVar11 ^ *(uint *)(&Camellia_SBOX + (uVar15 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar15 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar15 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar15 << 8) >> 0x18) + 0x300) * 4);
  uVar10 = uVar10 ^ (uVar11 >> 8 | uVar11 << 0x18) ^ uVar15;
  uVar14 = uVar14 ^ uVar15;
  if (param_1 != 0x80) {
    uVar15 = param_3[8] ^ uVar14 ^ 0x10e527fa;
    uVar11 = uVar10 ^ param_3[9] ^ 0xde682d1d;
    uVar15 = *(uint *)(&Camellia_SBOX + ((uVar15 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar15 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar15 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar15 << 8) >> 0x18) + 0x200) * 4);
    uVar9 = *(uint *)(&Camellia_SBOX + (((uVar11 << 8) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar11 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar11 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar11 << 0x10) >> 0x18) + 0x100) * 4) ^ uVar15;
    uVar11 = uVar12 ^ param_3[10] ^ uVar9;
    uVar9 = uVar18 ^ param_3[0xb] ^ (uVar15 >> 8 | uVar15 << 0x18) ^ uVar9;
    uVar16 = uVar9 ^ 0xb3e6c1fd;
    uVar25 = uVar11 ^ 0xb05688c2;
    param_3[6] = uVar11;
    uVar13 = *(uint *)(&Camellia_SBOX + (uVar25 >> 0x18) * 4);
    uVar15 = param_3[8] << 0xf;
    uVar19 = param_3[9] >> 0x11 | uVar15;
    uVar23 = *(uint *)(&Camellia_SBOX + ((uVar25 & 0xff) + 0x100) * 4);
    uVar17 = *(uint *)(&Camellia_SBOX + (((uVar25 << 0x10) >> 0x18) + 0x300) * 4);
    uVar24 = *(uint *)(&Camellia_SBOX + (uVar16 & 0xff) * 4);
    param_3[7] = uVar9;
    uVar17 = uVar17 ^ uVar23 ^ uVar13 ^
             *(uint *)(&Camellia_SBOX + (((uVar25 << 8) >> 0x18) + 0x200) * 4);
    uVar13 = *(uint *)(&Camellia_SBOX + (((uVar16 << 0x10) >> 0x18) + 0x100) * 4) ^
             uVar24 ^ *(uint *)(&Camellia_SBOX + ((uVar16 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar16 << 8) >> 0x18) + 0x300) * 4) ^ uVar17;
    uVar25 = param_3[10] >> 0x11 | param_3[9] << 0xf;
    param_3[10] = param_3[0xb] >> 0x11 | param_3[10] << 0xf;
    param_3[0xb] = param_3[0xb] << 0xf | param_3[8] >> 0x11;
    param_3[0x18] = uVar5 >> 0x13 | uVar4 << 0xd;
    param_3[0x1b] = uVar3 >> 0x13 | uVar2 << 0xd;
    param_3[0x1a] = uVar1 >> 0x13 | uVar8 << 0xd;
    uVar20 = (param_3[9] << 0xf) >> 0x11;
    param_3[0x19] = uVar7 >> 0x13 | uVar6 << 0xd;
    uVar1 = uVar9 >> 2 | uVar11 << 0x1e;
    uVar6 = param_3[8] ^ uVar14 ^ uVar13;
    uVar21 = uVar20 | uVar19 << 0xf;
    uVar13 = uVar13 ^ uVar10 ^ param_3[9] ^ (uVar17 >> 8 | uVar17 << 0x18);
    param_3[4] = uVar6;
    uVar3 = uVar11 >> 2 | uVar13 << 0x1e;
    uVar22 = uVar15 >> 0x11 | param_3[0xb] << 0xf;
    uVar17 = param_3[0xb] >> 0x11;
    uVar24 = uVar13 >> 2 | uVar6 << 0x1e;
    param_3[0x16] = uVar1;
    uVar8 = param_3[10] >> 0x11;
    uVar16 = uVar8 | uVar25 << 0xf;
    uVar5 = uVar6 >> 2 | uVar9 << 0x1e;
    uVar23 = uVar17 | param_3[10] << 0xf;
    param_3[0x20] = param_3[0x19] >> 0x11 | param_3[0x18] << 0xf;
    param_3[5] = uVar13;
    param_3[0x15] = uVar3;
    param_3[0x14] = uVar24;
    param_3[0x17] = uVar5;
    param_3[0xf] = uVar14 >> 0x11 | uVar18 << 0xf;
    uVar5 = uVar5 >> 2;
    param_3[0x23] = param_3[0x18] >> 0x11 | param_3[0x1b] << 0xf;
    param_3[0xe] = uVar18 >> 0x11 | uVar12 << 0xf;
    uVar18 = uVar22 >> 2;
    uVar7 = uVar5 | (uVar9 >> 2) << 0x1e;
    uVar1 = uVar1 >> 2;
    uVar2 = uVar1 | (uVar11 >> 2) << 0x1e;
    uVar3 = uVar3 >> 2;
    param_3[0x2a] = uVar7;
    uVar4 = uVar3 | (uVar13 >> 2) << 0x1e;
    param_3[0x29] = uVar2;
    uVar24 = uVar24 >> 2;
    param_3[0xd] = uVar12 >> 0x11 | uVar10 << 0xf;
    uVar6 = uVar24 | (uVar6 >> 2) << 0x1e;
    param_3[0x28] = uVar4;
    param_3[0xc] = uVar10 >> 0x11 | uVar14 << 0xf;
    uVar12 = uVar21 >> 2;
    param_3[0x2b] = uVar6;
    param_3[0x40] = uVar7 >> 0xd | uVar1 << 0x13;
    param_3[0x42] = uVar4 >> 0xd | uVar24 << 0x13;
    param_3[0x41] = uVar6 >> 0xd | uVar5 << 0x13;
    param_3[0x43] = uVar2 >> 0xd | uVar3 << 0x13;
    param_3[0x22] = param_3[0x1b] >> 0x11 | param_3[0x1a] << 0xf;
    uVar9 = uVar16 >> 2;
    param_3[0x21] = param_3[0x1a] >> 0x11 | param_3[0x19] << 0xf;
    param_3[0x2f] = param_3[0x20] >> 0xf | param_3[0x23] << 0x11;
    uVar11 = uVar23 >> 2;
    param_3[8] = uVar19;
    param_3[9] = uVar25;
    param_3[0x11] = uVar16;
    uVar7 = param_3[0xf] >> 2 | param_3[0xe] << 0x1e;
    uVar1 = param_3[0xe] >> 2;
    param_3[0x25] = uVar11 | uVar8 << 0x1e;
    param_3[0x24] = uVar9 | uVar20 << 0x1e;
    uVar2 = uVar1 | param_3[0xd] << 0x1e;
    uVar5 = param_3[0xd] >> 2;
    param_3[0x27] = uVar12 | (uVar15 >> 0x11) << 0x1e;
    uVar6 = uVar5 | param_3[0xc] << 0x1e;
    uVar3 = param_3[0xc] >> 2;
    param_3[0x10] = uVar21;
    uVar4 = uVar3 | param_3[0xf] << 0x1e;
    param_3[0x13] = uVar22;
    param_3[0x26] = uVar18 | uVar17 << 0x1e;
    param_3[0x2e] = param_3[0x23] >> 0xf | param_3[0x22] << 0x11;
    uVar14 = param_3[0x22] >> 0xf | param_3[0x21] << 0x11;
    param_3[0x12] = uVar23;
    uVar10 = param_3[0x21] >> 0xf | param_3[0x20] << 0x11;
    param_3[0x34] = uVar17 & 3 | uVar11 << 2;
    param_3[0x37] = uVar8 & 3 | uVar9 << 2;
    param_3[0x36] = uVar20 & 3 | uVar12 << 2;
    param_3[0x3b] = uVar2 >> 0xf | uVar5 << 0x11;
    param_3[0x35] = (uVar15 & 0x60000) >> 0x11 | uVar18 << 2;
    param_3[0x1d] = uVar2;
    param_3[0x30] = uVar2;
    param_3[0x1e] = uVar7;
    param_3[0x31] = uVar7;
    param_3[0x1c] = uVar6;
    param_3[0x1f] = uVar4;
    param_3[0x32] = uVar4;
    param_3[0x33] = uVar6;
    param_3[0x38] = uVar7 >> 0xf | uVar1 << 0x11;
    param_3[0x39] = uVar4 >> 0xf | (param_3[0xf] >> 2) << 0x11;
    param_3[0x3a] = uVar6 >> 0xf | uVar3 << 0x11;
    param_3[0x2c] = uVar10;
    param_3[0x2d] = uVar14;
    param_3[0x3c] = param_3[0x2e] >> 0x1e | uVar14 << 2;
    param_3[0x3f] = (param_3[0x21] << 0x11) >> 0x1e | uVar10 << 2;
    param_3[0x3e] = (param_3[0x20] << 0x11) >> 0x1e | param_3[0x2f] << 2;
    param_3[0x3d] = param_3[0x2f] >> 0x1e | param_3[0x2e] << 2;
    return 4;
  }
  param_3[4] = uVar14;
  param_3[5] = uVar10;
  uVar19 = uVar18 >> 0x11 | uVar12 << 0xf;
  uVar15 = uVar10 >> 0x11 | uVar14 << 0xf;
  uVar9 = uVar14 >> 0x11 | uVar18 << 0xf;
  uVar11 = uVar12 >> 0x11 | uVar10 << 0xf;
  param_3[7] = uVar18;
  param_3[0xc] = uVar15;
  uVar13 = uVar3 >> 0x11 | uVar2 << 0xf;
  param_3[0xd] = uVar11;
  param_3[0xb] = uVar1 >> 0x11 | uVar8 << 0xf;
  uVar15 = uVar15 << 0xf;
  uVar2 = (uVar10 << 0xf) >> 0x11 | uVar15;
  param_3[10] = uVar7 >> 0x11 | uVar6 << 0xf;
  uVar11 = uVar11 << 0xf;
  uVar6 = (uVar12 << 0xf) >> 0x11 | uVar11;
  param_3[0xf] = uVar9;
  param_3[6] = uVar12;
  uVar9 = uVar9 << 0xf;
  uVar7 = (uVar14 << 0xf) >> 0x11 | uVar9;
  param_3[0xe] = uVar19;
  param_3[9] = uVar5 >> 0x11 | uVar4 << 0xf;
  uVar19 = uVar19 << 0xf;
  uVar4 = (uVar18 << 0xf) >> 0x11 | uVar19;
  param_3[0x10] = uVar2;
  param_3[0x11] = uVar6;
  uVar1 = uVar4 << 0xf;
  param_3[0x12] = uVar4;
  param_3[0x14] = param_3[9] >> 2 | (uVar3 >> 0x11) << 0x1e;
  param_3[0x17] = uVar13 >> 2 | param_3[0xb] << 0x1e;
  param_3[0x16] = param_3[0xb] >> 2 | param_3[10] << 0x1e;
  uVar2 = uVar2 << 0xf;
  uVar3 = uVar11 >> 0x11 | uVar2;
  param_3[0x15] = param_3[10] >> 2 | param_3[9] << 0x1e;
  uVar6 = uVar6 << 0xf;
  uVar5 = uVar19 >> 0x11 | uVar6;
  param_3[0x13] = uVar7;
  uVar7 = uVar7 << 0xf;
  param_3[0x18] = uVar3;
  param_3[0x19] = uVar5;
  param_3[8] = uVar13;
  uVar12 = param_3[0x17];
  uVar3 = uVar3 << 0xf;
  uVar6 = uVar6 >> 0x11 | uVar3;
  uVar4 = (uVar15 >> 0x11 | uVar7) << 0xf;
  uVar8 = uVar2 >> 0x11 | uVar4;
  uVar15 = param_3[0x16];
  uVar2 = (uVar9 >> 0x11 | uVar1) << 0xf;
  uVar7 = uVar7 >> 0x11 | uVar2;
  param_3[0x1c] = uVar6;
  uVar5 = uVar5 << 0xf;
  uVar14 = uVar1 >> 0x11 | uVar5;
  param_3[0x1f] = uVar8;
  uVar1 = uVar14 << 2;
  uVar10 = uVar2 >> 0x1e | uVar1;
  param_3[0x1d] = uVar14;
  uVar6 = uVar6 << 2;
  uVar5 = uVar5 >> 0x1e | uVar6;
  param_3[0x1e] = uVar7;
  uVar8 = uVar8 << 2;
  uVar2 = uVar3 >> 0x1e | uVar8;
  param_3[0x28] = uVar10;
  uVar7 = uVar7 << 2;
  uVar3 = uVar4 >> 0x1e | uVar7;
  param_3[0x2b] = uVar5;
  uVar14 = uVar12 & 0x1ffff | (uVar12 >> 0x11) << 0x11;
  uVar18 = param_3[0x15] & 0x1ffff | param_3[0x15] & 0xfffe0000;
  uVar4 = param_3[0x14] & 0x1ffff | (param_3[0x14] >> 0x11) << 0x11;
  param_3[0x2a] = uVar2;
  uVar11 = uVar14 >> 0xf;
  param_3[0x29] = uVar3;
  uVar9 = uVar11 | uVar15 << 0x11;
  param_3[0x33] = uVar1 >> 0xf | uVar5 << 0x11;
  param_3[0x32] = uVar6 >> 0xf | uVar2 << 0x11;
  uVar1 = uVar18 >> 0xf;
  uVar5 = uVar4 >> 0xf;
  param_3[0x31] = uVar8 >> 0xf | uVar3 << 0x11;
  uVar3 = uVar15 >> 0xf | (param_3[0x15] & 0x1ffff) << 0x11;
  uVar2 = uVar1 | (param_3[0x14] & 0x1ffff) << 0x11;
  uVar6 = uVar5 | (uVar12 & 0x1ffff) << 0x11;
  param_3[0x30] = uVar7 >> 0xf | uVar10 << 0x11;
  param_3[0x1a] = uVar12 >> 0x11 | uVar15 << 0xf;
  param_3[0x20] = uVar18;
  param_3[0x21] = uVar15;
  param_3[0x1b] = param_3[0x14] >> 0x11 | uVar12 << 0xf;
  param_3[0x22] = uVar14;
  param_3[0x23] = uVar4;
  param_3[0x24] = uVar3;
  param_3[0x25] = uVar9;
  param_3[0x26] = uVar6;
  param_3[0x27] = uVar2;
  param_3[0x2c] = uVar9 >> 0xf | (uVar15 >> 0xf) << 0x11;
  param_3[0x2f] = uVar3 >> 0xf | uVar1 << 0x11;
  param_3[0x2e] = uVar2 >> 0xf | uVar5 << 0x11;
  param_3[0x2d] = uVar6 >> 0xf | uVar11 << 0x11;
  return 3;
}

