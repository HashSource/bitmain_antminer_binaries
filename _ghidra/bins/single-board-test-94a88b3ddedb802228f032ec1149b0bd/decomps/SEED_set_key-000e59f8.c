
void SEED_set_key(uchar *rawkey,SEED_KEY_SCHEDULE *ks)

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
  
  uVar12 = (uint)rawkey[9] << 0x10 | (uint)rawkey[8] << 0x18 | (uint)rawkey[0xb] |
           (uint)rawkey[10] << 8;
  uVar5 = (uint)rawkey[3] | (uint)rawkey[1] << 0x10 | (uint)*rawkey << 0x18 | (uint)rawkey[2] << 8;
  uVar14 = (uint)rawkey[5] << 0x10 | (uint)rawkey[4] << 0x18 | (uint)rawkey[7] |
           (uint)rawkey[6] << 8;
  uVar17 = uVar5 + uVar12 + 0x61c88647;
  uVar20 = (uint)rawkey[0xd] << 0x10 | (uint)rawkey[0xc] << 0x18 | (uint)rawkey[0xf] |
           (uint)rawkey[0xe] << 8;
  uVar5 = uVar5 >> 8;
  uVar6 = (uint)rawkey[7] << 0x18 | uVar5;
  uVar1 = uVar14 >> 8;
  uVar15 = (uint)rawkey[3] << 0x18 | uVar1;
  uVar2 = (uVar14 + 0x9e3779b9) - uVar20;
  uVar18 = (uint)rawkey[8] | uVar20 << 8;
  uVar13 = (uint)rawkey[0xc] | uVar12 << 8;
  uVar3 = uVar1 << 0x18 | uVar6 >> 8;
  uVar5 = uVar5 << 0x18 | uVar15 >> 8;
  uVar4 = (uVar12 << 8) >> 0x18 | uVar18 << 8;
  uVar1 = (uVar20 << 8) >> 0x18 | uVar13 << 8;
  uVar14 = uVar12 + 0xc3910c8d + uVar6;
  uVar20 = (0x3c6ef373 - uVar20) + uVar15;
  uVar8 = (uVar15 >> 8) << 0x18 | uVar3 >> 8;
  uVar7 = (uVar6 >> 8) << 0x18 | uVar5 >> 8;
  uVar9 = *(uint *)(&SS + ((uVar2 >> 0x18) + 0x300) * 4);
  ks->data[0] = *(uint *)(&SS + ((uVar17 >> 0x18) + 0x300) * 4) ^
                *(uint *)(&SS + (uVar17 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar17 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar17 * 0x100 >> 0x18) + 0x200) * 4);
  uVar17 = *(uint *)(&SS + ((uVar14 >> 0x18) + 0x300) * 4);
  uVar12 = *(uint *)(&SS + ((uVar20 >> 0x18) + 0x300) * 4);
  uVar21 = (uVar13 << 8) >> 0x18 | uVar4 << 8;
  ks->data[1] = *(uint *)(&SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4) ^
                *(uint *)(&SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4) ^
                uVar9 ^ *(uint *)(&SS + (uVar2 & 0xff) * 4);
  uVar2 = *(uint *)(&SS + (uVar20 & 0xff) * 4);
  ks->data[2] = uVar17 ^ *(uint *)(&SS + (uVar14 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar14 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar14 * 0x100 >> 0x18) + 0x200) * 4);
  uVar10 = (uVar15 + 0x78dde6e6) - uVar18;
  uVar15 = (uVar5 + 0xe3779b99) - uVar4;
  uVar22 = uVar13 + 0xe443234 + uVar3;
  uVar11 = (-0xe443234 - uVar18) + uVar5;
  ks->data[3] = uVar12 ^ uVar2 ^ *(uint *)(&SS + ((uVar20 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar20 * 0x100 >> 0x18) + 0x200) * 4);
  uVar20 = uVar6 + uVar13 + 0x8722191a;
  uVar19 = uVar1 + 0x3910c8cd + uVar8;
  uVar12 = (uVar18 << 8) >> 0x18 | uVar1 << 8;
  uVar14 = uVar3 + uVar1 + 0x1c886467;
  uVar17 = (uVar5 >> 8) << 0x18 | uVar8 >> 8;
  uVar16 = (uVar3 >> 8) << 0x18 | uVar7 >> 8;
  uVar6 = (uVar4 << 8) >> 0x18 | uVar12 << 8;
  ks->data[4] = *(uint *)(&SS + ((uVar20 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar20 >> 0x18) + 0x300) * 4) ^
                *(uint *)(&SS + (uVar20 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar20 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = *(uint *)(&SS + ((uVar22 >> 0x18) + 0x300) * 4);
  uVar5 = *(uint *)(&SS + ((uVar11 >> 0x18) + 0x300) * 4);
  uVar9 = *(uint *)(&SS + ((uVar14 >> 0x18) + 0x300) * 4);
  ks->data[5] = *(uint *)(&SS + ((uVar10 * 0x100 >> 0x18) + 0x200) * 4) ^
                *(uint *)(&SS + ((uVar10 >> 0x18) + 0x300) * 4) ^
                *(uint *)(&SS + (uVar10 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar10 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar20 = *(uint *)(&SS + ((uVar15 >> 0x18) + 0x300) * 4);
  uVar2 = *(uint *)(&SS + ((uVar19 >> 0x18) + 0x300) * 4);
  uVar23 = (uVar1 << 8) >> 0x18 | uVar21 << 8;
  uVar1 = *(uint *)(&SS + (uVar11 & 0xff) * 4);
  ks->data[6] = uVar3 ^ *(uint *)(&SS + (uVar22 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar22 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar22 * 0x100 >> 0x18) + 0x200) * 4);
  uVar10 = *(uint *)(&SS + (uVar14 & 0xff) * 4);
  uVar13 = *(uint *)(&SS + (uVar15 & 0xff) * 4);
  ks->data[7] = uVar5 ^ uVar1 ^ *(uint *)(&SS + ((uVar11 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar11 * 0x100 >> 0x18) + 0x200) * 4);
  uVar22 = *(uint *)(&SS + (uVar19 & 0xff) * 4);
  uVar3 = (uVar7 >> 8) << 0x18 | uVar17 >> 8;
  uVar11 = *(uint *)(&SS + ((uVar15 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = *(uint *)(&SS + ((uVar15 * 0x100 >> 0x18) + 0x200) * 4);
  uVar15 = *(uint *)(&SS + ((uVar19 * 0x100 >> 0x18) + 0x200) * 4);
  uVar18 = (uVar8 >> 8) << 0x18 | uVar16 >> 8;
  uVar1 = *(uint *)(&SS + ((uVar19 * 0x10000 >> 0x18) + 0x100) * 4);
  ks->data[8] = uVar9 ^ uVar10 ^ *(uint *)(&SS + ((uVar14 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar14 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[9] = uVar20 ^ uVar13 ^ uVar11 ^ uVar5;
  uVar19 = (uVar7 + 0x8dde6e67) - uVar21;
  uVar20 = uVar12 + 0xe4432331 + uVar17;
  uVar13 = (uVar12 << 8) >> 0x18 | uVar23 << 8;
  uVar7 = (-0x3910c8cd - uVar4) + uVar7;
  ks->data[10] = uVar2 ^ uVar22 ^ uVar1 ^ uVar15;
  uVar5 = (0x1bbcdccf - uVar21) + uVar16;
  uVar1 = (uVar16 + 0x3779b99e) - uVar23;
  uVar14 = uVar17 + uVar6 + 0xc8864662;
  uVar12 = uVar12 + uVar8 + 0x72219199;
  uVar11 = (uVar21 << 8) >> 0x18 | uVar6 << 8;
  uVar15 = (uVar16 >> 8) << 0x18 | uVar3 >> 8;
  uVar8 = (uVar17 >> 8) << 0x18 | uVar18 >> 8;
  uVar9 = *(uint *)(&SS + ((uVar19 >> 0x18) + 0x300) * 4);
  ks->data[0xb] =
       *(uint *)(&SS + ((uVar7 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar7 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar7 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar7 * 0x100 >> 0x18) + 0x200) * 4);
  uVar17 = *(uint *)(&SS + ((uVar20 >> 0x18) + 0x300) * 4);
  ks->data[0xc] =
       *(uint *)(&SS + ((uVar12 * 0x100 >> 0x18) + 0x200) * 4) ^
       *(uint *)(&SS + ((uVar12 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar12 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar12 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4);
  uVar2 = *(uint *)(&SS + ((uVar14 >> 0x18) + 0x300) * 4);
  uVar7 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4);
  uVar10 = (uVar23 << 8) >> 0x18 | uVar11 << 8;
  ks->data[0xd] =
       uVar9 ^ *(uint *)(&SS + (uVar19 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar19 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar19 * 0x100 >> 0x18) + 0x200) * 4);
  uVar16 = *(uint *)(&SS + (uVar5 & 0xff) * 4);
  uVar9 = *(uint *)(&SS + (uVar14 & 0xff) * 4);
  ks->data[0xe] =
       *(uint *)(&SS + ((uVar20 * 0x100 >> 0x18) + 0x200) * 4) ^
       uVar17 ^ *(uint *)(&SS + (uVar20 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar20 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar20 = *(uint *)(&SS + ((uVar14 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar14 = *(uint *)(&SS + ((uVar14 * 0x100 >> 0x18) + 0x200) * 4);
  uVar17 = *(uint *)(&SS + (uVar1 & 0xff) * 4);
  uVar12 = *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  ks->data[0xf] =
       *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4) ^ uVar4 ^ uVar16 ^
       *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x10] = uVar14 ^ uVar9 ^ uVar2 ^ uVar20;
  uVar9 = (0x6ef3733c - uVar23) + uVar18;
  uVar20 = uVar6 + 0x910c8cc4 + uVar3;
  uVar5 = (uVar18 + 0xdde6e678) - uVar13;
  uVar16 = (uVar6 << 8) >> 0x18 | uVar13 << 8;
  uVar4 = (uVar18 >> 8) << 0x18 | uVar15 >> 8;
  uVar18 = (-0x4432330f - uVar13) + uVar8;
  ks->data[0x11] = uVar7 ^ uVar17 ^ uVar12 ^ uVar1;
  uVar2 = uVar11 + 0x4432330f + uVar15;
  uVar14 = uVar3 + uVar11 + 0x22191988;
  uVar1 = (uVar3 >> 8) << 0x18 | uVar8 >> 8;
  uVar12 = uVar15 + uVar10 + 0x8864661d;
  ks->data[0x12] =
       *(uint *)(&SS + ((uVar20 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar20 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar20 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar20 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4);
  uVar20 = *(uint *)(&SS + ((uVar14 >> 0x18) + 0x300) * 4);
  uVar3 = *(uint *)(&SS + ((uVar2 >> 0x18) + 0x300) * 4);
  uVar17 = *(uint *)(&SS + ((uVar18 >> 0x18) + 0x300) * 4);
  ks->data[0x13] =
       *(uint *)(&SS + ((uVar9 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar9 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar9 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar9 * 0x100 >> 0x18) + 0x200) * 4);
  uVar19 = *(uint *)(&SS + ((uVar12 >> 0x18) + 0x300) * 4);
  uVar9 = (uVar13 << 8) >> 0x18 | uVar10 << 8;
  uVar7 = (uVar11 << 8) >> 0x18 | uVar16 << 8;
  ks->data[0x14] =
       *(uint *)(&SS + ((uVar14 * 0x100 >> 0x18) + 0x200) * 4) ^
       uVar20 ^ *(uint *)(&SS + (uVar14 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar14 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar14 = *(uint *)(&SS + (uVar2 & 0xff) * 4);
  uVar20 = *(uint *)(&SS + (uVar18 & 0xff) * 4);
  ks->data[0x15] =
       uVar6 ^ *(uint *)(&SS + (uVar5 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = *(uint *)(&SS + (uVar12 & 0xff) * 4);
  ks->data[0x16] =
       uVar14 ^ uVar3 ^ *(uint *)(&SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4);
  uVar13 = *(uint *)(&SS + ((uVar18 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = *(uint *)(&SS + ((uVar18 * 0x100 >> 0x18) + 0x200) * 4);
  uVar21 = (uVar8 + 0x779b99e3) - uVar16;
  uVar14 = uVar10 + 0x10c8cc3a + uVar4;
  uVar3 = ((uVar8 >> 8) << 0x18 | uVar4 >> 8) + uVar9 + 0x432330e5;
  uVar11 = (-0x10c8cc3a - uVar16) + uVar1;
  uVar2 = (uVar1 + 0xde6e678d) - uVar7;
  uVar18 = uVar4 + uVar9 + 0x21919873;
  uVar16 = ((uVar15 >> 8) << 0x18 | uVar1 >> 8) + (-0x432330e5 - uVar7);
  uVar4 = *(uint *)(&SS + ((uVar14 >> 0x18) + 0x300) * 4);
  ks->data[0x18] =
       uVar19 ^ uVar6 ^ *(uint *)(&SS + ((uVar12 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar12 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x17] = uVar5 ^ uVar17 ^ uVar20 ^ uVar13;
  uVar9 = *(uint *)(&SS + ((uVar11 >> 0x18) + 0x300) * 4);
  uVar10 = *(uint *)(&SS + ((uVar3 >> 0x18) + 0x300) * 4);
  uVar7 = *(uint *)(&SS + ((uVar2 >> 0x18) + 0x300) * 4);
  uVar1 = *(uint *)(&SS + ((uVar18 >> 0x18) + 0x300) * 4);
  uVar17 = *(uint *)(&SS + ((uVar16 >> 0x18) + 0x300) * 4);
  uVar5 = *(uint *)(&SS + (uVar14 & 0xff) * 4);
  ks->data[0x19] =
       *(uint *)(&SS + ((uVar21 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar21 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar21 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar21 * 0x100 >> 0x18) + 0x200) * 4);
  uVar13 = *(uint *)(&SS + (uVar11 & 0xff) * 4);
  uVar19 = *(uint *)(&SS + (uVar18 & 0xff) * 4);
  uVar15 = *(uint *)(&SS + (uVar2 & 0xff) * 4);
  uVar6 = *(uint *)(&SS + (uVar3 & 0xff) * 4);
  ks->data[0x1a] =
       *(uint *)(&SS + ((uVar14 * 0x100 >> 0x18) + 0x200) * 4) ^
       uVar4 ^ uVar5 ^ *(uint *)(&SS + ((uVar14 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar12 = *(uint *)(&SS + (uVar16 & 0xff) * 4);
  uVar8 = *(uint *)(&SS + ((uVar18 * 0x100 >> 0x18) + 0x200) * 4);
  uVar4 = *(uint *)(&SS + ((uVar18 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar14 = *(uint *)(&SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar20 = *(uint *)(&SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar18 = *(uint *)(&SS + ((uVar16 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar2 = *(uint *)(&SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = *(uint *)(&SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4);
  uVar5 = *(uint *)(&SS + ((uVar16 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x1b] =
       uVar9 ^ uVar13 ^ *(uint *)(&SS + ((uVar11 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar11 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x1c] = uVar4 ^ uVar1 ^ uVar19 ^ uVar8;
  ks->data[0x1d] = uVar7 ^ uVar15 ^ uVar14 ^ uVar2;
  ks->data[0x1e] = uVar10 ^ uVar6 ^ uVar20 ^ uVar3;
  ks->data[0x1f] = uVar5 ^ uVar17 ^ uVar12 ^ uVar18;
  return;
}

