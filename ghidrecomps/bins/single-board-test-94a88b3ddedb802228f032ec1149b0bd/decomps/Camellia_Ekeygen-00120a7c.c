
undefined4 Camellia_Ekeygen(int param_1,byte *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
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
  uint local_48;
  
  uVar5 = (uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18;
  uVar10 = uVar5 ^ param_2[3] | (uint)param_2[2] << 8;
  *param_3 = uVar10;
  uVar6 = (uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18;
  uVar7 = uVar6 ^ param_2[7] | (uint)param_2[6] << 8;
  param_3[1] = uVar7;
  uVar8 = (uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18;
  uVar19 = uVar8 ^ param_2[0xb] | (uint)param_2[10] << 8;
  param_3[2] = uVar19;
  uVar9 = (uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18;
  uVar1 = uVar9 ^ param_2[0xf] | (uint)param_2[0xe] << 8;
  param_3[3] = uVar1;
  if (param_1 == 0x80) {
    uVar11 = 0;
    local_48 = 0;
    uVar4 = uVar7;
    uVar15 = uVar1;
    uVar12 = uVar10;
    uVar2 = uVar19;
  }
  else {
    uVar11 = ((uint)param_2[0x11] << 0x10 | (uint)param_2[0x10] << 0x18) ^ (uint)param_2[0x13] |
             (uint)param_2[0x12] << 8;
    param_3[8] = uVar11;
    local_48 = ((uint)param_2[0x15] << 0x10 | (uint)param_2[0x14] << 0x18) ^ (uint)param_2[0x17] |
               (uint)param_2[0x16] << 8;
    param_3[9] = local_48;
    if (param_1 == 0xc0) {
      uVar2 = ~uVar11;
      uVar15 = ~local_48;
      param_3[10] = uVar2;
      param_3[0xb] = uVar15;
    }
    else {
      uVar2 = ((uint)param_2[0x19] << 0x10 | (uint)param_2[0x18] << 0x18) ^ (uint)param_2[0x1b] |
              (uint)param_2[0x1a] << 8;
      param_3[10] = uVar2;
      uVar15 = ((uint)param_2[0x1d] << 0x10 | (uint)param_2[0x1c] << 0x18) ^ (uint)param_2[0x1f] |
               (uint)param_2[0x1e] << 8;
      param_3[0xb] = uVar15;
    }
    uVar4 = local_48 ^ uVar7;
    uVar15 = uVar15 ^ uVar1;
    uVar12 = uVar11 ^ uVar10;
    uVar2 = uVar2 ^ uVar19;
  }
  uVar12 = uVar12 ^ 0xa09e667f;
  uVar4 = uVar4 ^ 0x3bcc908b;
  uVar12 = *(uint *)(&Camellia_SBOX + ((uVar12 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar12 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x200) * 4);
  uVar4 = *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
          *(uint *)(&Camellia_SBOX + ((uVar4 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x300) * 4) ^ uVar12;
  uVar2 = uVar4 ^ uVar2;
  uVar23 = uVar2 ^ 0xb67ae858;
  uVar15 = uVar4 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar15;
  uVar12 = uVar15 ^ 0x4caa73b2;
  uVar4 = *(uint *)(&Camellia_SBOX + (((uVar23 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(&Camellia_SBOX + ((uVar23 & 0xff) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (uVar23 >> 0x18) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar23 << 0x10) >> 0x18) + 0x300) * 4);
  uVar16 = *(uint *)(&Camellia_SBOX + (uVar12 & 0xff) * 4) ^
           *(uint *)(&Camellia_SBOX + ((uVar12 >> 0x18) + 0x200) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x300) * 4) ^ uVar4;
  uVar11 = uVar11 ^ uVar16;
  uVar12 = uVar11 ^ 0xc6ef372f;
  uVar16 = local_48 ^ (uVar4 >> 8 | uVar4 << 0x18) ^ uVar16;
  uVar4 = uVar16 ^ 0xe94f82be;
  uVar12 = *(uint *)(&Camellia_SBOX + ((uVar12 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar12 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x200) * 4);
  uVar23 = *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
           *(uint *)(&Camellia_SBOX + ((uVar4 >> 0x18) + 0x200) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x300) * 4) ^ uVar12;
  uVar4 = uVar2 ^ uVar19 ^ uVar23;
  uVar23 = uVar23 ^ uVar15 ^ uVar1 ^ (uVar12 >> 8 | uVar12 << 0x18);
  uVar12 = uVar4 ^ 0x54ff53a5;
  uVar15 = uVar23 ^ 0xf1d36f1c;
  uVar12 = *(uint *)(&Camellia_SBOX + ((uVar12 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar12 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x200) * 4);
  uVar15 = *(uint *)(&Camellia_SBOX + ((uVar15 >> 0x18) + 0x200) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar15 & 0xff) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar15 << 0x10) >> 0x18) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar15 << 8) >> 0x18) + 0x300) * 4) ^ uVar12;
  uVar11 = uVar15 ^ uVar11;
  uVar15 = uVar16 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar15;
  if (param_1 == 0x80) {
    uVar12 = uVar15 >> 0x11 | uVar11 << 0xf;
    param_3[0xc] = uVar12;
    uVar13 = uVar11 >> 0x11 | uVar23 << 0xf;
    uVar16 = uVar23 >> 0x11 | uVar4 << 0xf;
    uVar2 = uVar4 >> 0x11 | uVar15 << 0xf;
    uVar17 = uVar6 >> 0x11 | uVar10 << 0xf;
    uVar10 = uVar2 << 0xf;
    uVar14 = (uVar4 << 0xf) >> 0x11 | uVar10;
    param_3[4] = uVar11;
    param_3[0xb] = uVar5 >> 0x11 | uVar1 << 0xf;
    param_3[9] = uVar8 >> 0x11 | uVar7 << 0xf;
    uVar1 = uVar16 << 0xf;
    uVar24 = (uVar23 << 0xf) >> 0x11 | uVar1;
    param_3[10] = uVar9 >> 0x11 | uVar19 << 0xf;
    uVar12 = uVar12 << 0xf;
    uVar9 = (uVar15 << 0xf) >> 0x11 | uVar12;
    param_3[5] = uVar15;
    uVar5 = uVar13 << 0xf;
    uVar15 = (uVar11 << 0xf) >> 0x11 | uVar5;
    param_3[6] = uVar4;
    param_3[0x14] = param_3[9] >> 2 | (uVar6 >> 0x11) << 0x1e;
    param_3[0x17] = uVar17 >> 2 | param_3[0xb] << 0x1e;
    param_3[7] = uVar23;
    param_3[0x16] = param_3[0xb] >> 2 | param_3[10] << 0x1e;
    param_3[0x15] = param_3[10] >> 2 | param_3[9] << 0x1e;
    uVar6 = uVar15 << 0xf;
    param_3[0xe] = uVar16;
    param_3[0xf] = uVar13;
    uVar7 = uVar9 << 0xf;
    uVar10 = uVar10 >> 0x11 | uVar7;
    uVar8 = uVar24 << 0xf;
    param_3[0xd] = uVar2;
    param_3[0x12] = uVar24;
    param_3[0x10] = uVar9;
    uVar9 = uVar14 << 0xf;
    uVar19 = uVar1 >> 0x11 | uVar9;
    param_3[0x13] = uVar15;
    param_3[0x18] = uVar10;
    param_3[0x1b] = param_3[0x14] >> 0x11 | param_3[0x17] << 0xf;
    uVar10 = uVar10 << 0xf;
    uVar9 = uVar9 >> 0x11 | uVar10;
    param_3[0x19] = uVar19;
    param_3[0x1c] = uVar9;
    param_3[0x11] = uVar14;
    param_3[0x1a] = param_3[0x17] >> 0x11 | param_3[0x16] << 0xf;
    param_3[8] = uVar17;
    uVar1 = (uVar12 >> 0x11 | uVar6) << 0xf;
    uVar7 = uVar7 >> 0x11 | uVar1;
    param_3[0x1f] = uVar7;
    uVar5 = (uVar5 >> 0x11 | uVar8) << 0xf;
    uVar4 = uVar6 >> 0x11 | uVar5;
    uVar19 = uVar19 << 0xf;
    uVar8 = uVar8 >> 0x11 | uVar19;
    uVar6 = uVar4 << 2;
    uVar11 = uVar1 >> 0x1e | uVar6;
    uVar1 = uVar8 << 2;
    uVar15 = uVar5 >> 0x1e | uVar1;
    param_3[0x1d] = uVar8;
    uVar12 = param_3[0x14] & 0x1ffff;
    param_3[0x1e] = uVar4;
    param_3[0x20] = param_3[0x15] & 0x1ffff | param_3[0x15] & 0xfffe0000;
    uVar9 = uVar9 << 2;
    uVar2 = uVar19 >> 0x1e | uVar9;
    param_3[0x28] = uVar15;
    uVar7 = uVar7 << 2;
    uVar5 = uVar10 >> 0x1e | uVar7;
    param_3[0x2b] = uVar2;
    uVar4 = uVar12 | param_3[0x1b] << 0x11;
    uVar23 = param_3[0x1b] >> 0xf;
    uVar19 = uVar23 | param_3[0x1a] << 0x11;
    uVar8 = param_3[0x1a] >> 0xf;
    param_3[0x2a] = uVar5;
    uVar24 = uVar8 | param_3[0x16] & 0xfffe0000;
    param_3[0x29] = uVar11;
    uVar16 = uVar24 >> 0xf;
    param_3[0x30] = uVar6 >> 0xf | uVar15 << 0x11;
    uVar6 = param_3[0x20] >> 0xf | uVar12 << 0x11;
    param_3[0x33] = uVar1 >> 0xf | uVar2 << 0x11;
    param_3[0x32] = uVar9 >> 0xf | uVar5 << 0x11;
    uVar1 = uVar4 >> 0xf;
    uVar9 = uVar19 >> 0xf;
    uVar10 = uVar16 | param_3[0x20] << 0x11;
    param_3[0x31] = uVar7 >> 0xf | uVar11 << 0x11;
    uVar5 = uVar1 | uVar23 << 0x11;
    uVar7 = uVar9 | uVar8 << 0x11;
    param_3[0x21] = uVar24;
    uVar3 = 3;
    param_3[0x22] = uVar19;
    param_3[0x23] = uVar4;
    param_3[0x24] = uVar10;
    param_3[0x25] = uVar7;
    param_3[0x26] = uVar5;
    param_3[0x27] = uVar6;
    param_3[0x2c] = uVar7 >> 0xf | uVar16 << 0x11;
    param_3[0x2f] = uVar10 >> 0xf | (param_3[0x20] >> 0xf) << 0x11;
    param_3[0x2e] = uVar6 >> 0xf | uVar1 << 0x11;
    param_3[0x2d] = uVar5 >> 0xf | uVar9 << 0x11;
  }
  else {
    uVar14 = param_3[8];
    uVar17 = param_3[9];
    uVar2 = uVar11 ^ uVar14 ^ 0x10e527fa;
    uVar12 = uVar15 ^ uVar17 ^ 0xde682d1d;
    uVar16 = param_3[8];
    uVar24 = *(uint *)(&Camellia_SBOX + ((uVar2 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar2 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar2 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar2 << 8) >> 0x18) + 0x200) * 4);
    uVar2 = *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar12 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar12 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x100) * 4) ^ uVar24;
    uVar18 = uVar4 ^ param_3[10] ^ uVar2;
    param_3[8] = uVar16 << 0xf | param_3[9] >> 0x11;
    uVar21 = uVar18 ^ 0xb05688c2;
    uVar2 = uVar23 ^ param_3[0xb] ^ (uVar24 >> 8 | uVar24 << 0x18) ^ uVar2;
    uVar12 = uVar2 ^ 0xb3e6c1fd;
    uVar24 = uVar16 >> 0x11 | param_3[0xb] << 0xf;
    param_3[7] = uVar2;
    param_3[9] = param_3[9] << 0xf | param_3[10] >> 0x11;
    uVar22 = *(uint *)(&Camellia_SBOX + ((uVar21 & 0xff) + 0x100) * 4);
    uVar20 = *(uint *)(&Camellia_SBOX + ((uVar12 >> 0x18) + 0x200) * 4);
    uVar13 = *(uint *)(&Camellia_SBOX + (uVar12 & 0xff) * 4);
    param_3[10] = param_3[10] << 0xf | param_3[0xb] >> 0x11;
    uVar25 = *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x100) * 4);
    uVar16 = *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x300) * 4);
    uVar12 = uVar22 ^ *(uint *)(&Camellia_SBOX + (uVar21 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar21 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar21 << 8) >> 0x18) + 0x200) * 4);
    param_3[6] = uVar18;
    param_3[0x18] = uVar8 >> 0x13 | uVar7 << 0xd;
    uVar7 = uVar2 >> 2 | uVar18 << 0x1e;
    param_3[0x1b] = uVar6 >> 0x13 | uVar10 << 0xd;
    param_3[0x1a] = uVar5 >> 0x13 | uVar1 << 0xd;
    uVar1 = uVar20 ^ uVar13 ^ uVar25 ^ uVar16 ^ uVar12;
    uVar6 = uVar15 ^ uVar17 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar1;
    param_3[0x19] = uVar9 >> 0x13 | uVar19 << 0xd;
    uVar1 = uVar1 ^ uVar11 ^ uVar14;
    uVar12 = uVar6 >> 2 | uVar1 << 0x1e;
    param_3[4] = uVar1;
    uVar14 = param_3[9] >> 0x11;
    uVar5 = uVar1 >> 2 | uVar2 << 0x1e;
    uVar16 = param_3[10] >> 0x11;
    uVar8 = uVar18 >> 2 | uVar6 << 0x1e;
    uVar17 = uVar14 | param_3[8] << 0xf;
    param_3[0x13] = param_3[8] >> 0x11 | uVar24 << 0xf;
    param_3[0x12] = (param_3[0xb] << 0xf) >> 0x11 | param_3[10] << 0xf;
    uVar13 = uVar16 | param_3[9] << 0xf;
    param_3[0x20] = param_3[0x19] >> 0x11 | param_3[0x18] << 0xf;
    param_3[0x23] = param_3[0x18] >> 0x11 | param_3[0x1b] << 0xf;
    param_3[5] = uVar6;
    uVar10 = uVar5 >> 2;
    param_3[0x15] = uVar8;
    uVar19 = uVar10 | (uVar2 >> 2) << 0x1e;
    param_3[0x14] = uVar12;
    param_3[0x17] = uVar5;
    param_3[0x16] = uVar7;
    param_3[0xc] = uVar15 >> 0x11 | uVar11 << 0xf;
    param_3[0x2a] = uVar19;
    param_3[0xf] = uVar11 >> 0x11 | uVar23 << 0xf;
    param_3[0xe] = uVar23 >> 0x11 | uVar4 << 0xf;
    param_3[0xd] = uVar4 >> 0x11 | uVar15 << 0xf;
    uVar7 = uVar7 >> 2;
    param_3[0x22] = param_3[0x1b] >> 0x11 | param_3[0x1a] << 0xf;
    uVar5 = uVar7 | (uVar18 >> 2) << 0x1e;
    uVar8 = uVar8 >> 2;
    uVar9 = uVar8 | (uVar6 >> 2) << 0x1e;
    uVar12 = uVar12 >> 2;
    param_3[0x29] = uVar5;
    uVar4 = uVar12 | (uVar1 >> 2) << 0x1e;
    param_3[0x28] = uVar9;
    param_3[0x21] = param_3[0x1a] >> 0x11 | param_3[0x19] << 0xf;
    uVar15 = uVar17 >> 2;
    uVar1 = param_3[0x13];
    param_3[0x2b] = uVar4;
    param_3[0x40] = uVar19 >> 0xd | uVar7 << 0x13;
    uVar2 = uVar13 >> 2;
    uVar6 = param_3[0x12];
    param_3[0x42] = uVar9 >> 0xd | uVar12 << 0x13;
    param_3[0x41] = uVar4 >> 0xd | uVar10 << 0x13;
    uVar9 = param_3[0xc] >> 2;
    param_3[0x43] = uVar5 >> 0xd | uVar8 << 0x13;
    param_3[0x2f] = param_3[0x20] >> 0xf | param_3[0x23] << 0x11;
    uVar10 = param_3[0xd] >> 2 | param_3[0xc] << 0x1e;
    uVar19 = param_3[0xf] >> 2;
    uVar8 = uVar9 | param_3[0xf] << 0x1e;
    uVar4 = uVar19 | param_3[0xe] << 0x1e;
    uVar5 = param_3[0xe] >> 2;
    uVar7 = uVar5 | param_3[0xd] << 0x1e;
    param_3[0x2e] = param_3[0x23] >> 0xf | param_3[0x22] << 0x11;
    param_3[0x11] = uVar13;
    param_3[0x25] = uVar6 >> 2 | uVar16 << 0x1e;
    param_3[0x24] = uVar2 | uVar14 << 0x1e;
    param_3[0x27] = uVar15 | uVar1 << 0x1e;
    param_3[0xb] = uVar24;
    param_3[0x26] = uVar1 >> 2 | uVar6 << 0x1e;
    param_3[0x37] = uVar16 & 3 | uVar2 << 2;
    param_3[0x35] = uVar1 & 3 | (uVar1 >> 2) << 2;
    param_3[0x2d] = param_3[0x22] >> 0xf | param_3[0x21] << 0x11;
    param_3[0x3b] = uVar7 >> 0xf | (param_3[0xd] >> 2) << 0x11;
    param_3[0x36] = uVar14 & 3 | uVar15 << 2;
    param_3[0x10] = uVar17;
    param_3[0x34] = uVar6 & 3 | (uVar6 >> 2) << 2;
    uVar1 = param_3[0x21] >> 0xf | param_3[0x20] << 0x11;
    param_3[0x1d] = uVar7;
    param_3[0x2c] = uVar1;
    param_3[0x30] = uVar7;
    uVar3 = 4;
    param_3[0x1c] = uVar10;
    param_3[0x1e] = uVar4;
    param_3[0x1f] = uVar8;
    param_3[0x31] = uVar4;
    param_3[0x32] = uVar8;
    param_3[0x33] = uVar10;
    param_3[0x38] = uVar4 >> 0xf | uVar5 << 0x11;
    param_3[0x3a] = uVar10 >> 0xf | uVar9 << 0x11;
    param_3[0x39] = uVar8 >> 0xf | uVar19 << 0x11;
    param_3[0x3c] = param_3[0x2e] >> 0x1e | param_3[0x2d] << 2;
    param_3[0x3f] = param_3[0x2d] >> 0x1e | uVar1 << 2;
    param_3[0x3e] = (param_3[0x20] << 0x11) >> 0x1e | param_3[0x2f] << 2;
    param_3[0x3d] = param_3[0x2f] >> 0x1e | param_3[0x2e] << 2;
  }
  return uVar3;
}

