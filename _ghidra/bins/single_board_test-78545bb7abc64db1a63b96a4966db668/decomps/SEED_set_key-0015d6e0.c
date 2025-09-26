
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
  
  uVar9 = (uint)rawkey[0xf] | (uint)rawkey[0xd] << 0x10 | (uint)rawkey[0xc] << 0x18 |
          (uint)rawkey[0xe] << 8;
  uVar5 = (uint)rawkey[1] << 0x10 | (uint)*rawkey << 0x18 | (uint)rawkey[3] | (uint)rawkey[2] << 8;
  uVar2 = (uint)rawkey[0xb] | (uint)rawkey[9] << 0x10 | (uint)rawkey[8] << 0x18 |
          (uint)rawkey[10] << 8;
  uVar3 = (uint)rawkey[5] << 0x10 | (uint)rawkey[4] << 0x18 | (uint)rawkey[7] | (uint)rawkey[6] << 8
  ;
  uVar18 = (uint)rawkey[0xc] | uVar2 << 8;
  uVar1 = uVar3 >> 8;
  uVar16 = (uint)rawkey[3] << 0x18 | uVar1;
  uVar10 = (uint)rawkey[8] | uVar9 << 8;
  uVar4 = uVar5 >> 8;
  uVar13 = (uint)rawkey[7] << 0x18 | uVar4;
  uVar12 = (uVar2 << 8) >> 0x18 | uVar10 << 8;
  uVar6 = uVar5 + uVar2 + 0x61c88647;
  uVar1 = uVar1 << 0x18 | uVar13 >> 8;
  uVar5 = uVar4 << 0x18 | uVar16 >> 8;
  uVar4 = (uVar3 + 0x9e3779b9) - uVar9;
  uVar3 = uVar2 + 0xc3910c8d + uVar13;
  uVar11 = (uVar9 << 8) >> 0x18 | uVar18 << 8;
  ks->data[0] = *(uint *)(&SS + (uVar6 & 0xff) * 4) ^ *(uint *)(&SS + ((uVar6 >> 0x18) + 0x300) * 4)
                ^ *(uint *)(&SS + ((uVar6 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar6 * 0x100 >> 0x18) + 0x200) * 4);
  uVar7 = *(uint *)(&SS + (uVar3 & 0xff) * 4);
  uVar14 = *(uint *)(&SS + ((uVar3 >> 0x18) + 0x300) * 4);
  uVar8 = *(uint *)(&SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  ks->data[1] = *(uint *)(&SS + (uVar4 & 0xff) * 4) ^ *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4)
                ^ *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar2 = (-0xe443234 - uVar10) + uVar5;
  uVar4 = (0x3c6ef373 - uVar9) + uVar16;
  uVar17 = (uVar16 + 0x78dde6e6) - uVar10;
  uVar6 = (uVar10 << 8) >> 0x18 | uVar11 << 8;
  uVar15 = (uVar16 >> 8) << 0x18 | uVar1 >> 8;
  uVar9 = uVar18 + 0xe443234 + uVar1;
  uVar16 = *(uint *)(&SS + (uVar4 & 0xff) * 4);
  ks->data[2] = uVar7 ^ uVar14 ^ uVar8 ^ *(uint *)(&SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4);
  uVar14 = uVar13 + uVar18 + 0x8722191a;
  uVar8 = uVar1 + uVar11 + 0x1c886467;
  uVar19 = (uVar13 >> 8) << 0x18 | uVar5 >> 8;
  uVar7 = (uVar5 + 0xe3779b99) - uVar12;
  uVar10 = (uVar18 << 8) >> 0x18 | uVar12 << 8;
  uVar3 = *(uint *)(&SS + ((uVar14 >> 0x18) + 0x300) * 4);
  uVar13 = *(uint *)(&SS + (uVar14 & 0xff) * 4);
  ks->data[3] = uVar16 ^ *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^
                *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar4 = *(uint *)(&SS + ((uVar17 >> 0x18) + 0x300) * 4);
  uVar18 = *(uint *)(&SS + ((uVar9 >> 0x18) + 0x300) * 4);
  uVar16 = *(uint *)(&SS + ((uVar2 >> 0x18) + 0x300) * 4);
  ks->data[4] = *(uint *)(&SS + ((uVar14 * 0x100 >> 0x18) + 0x200) * 4) ^
                uVar13 ^ uVar3 ^ *(uint *)(&SS + ((uVar14 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar14 = (uVar1 >> 8) << 0x18 | uVar19 >> 8;
  uVar13 = (uVar11 << 8) >> 0x18 | uVar10 << 8;
  uVar3 = *(uint *)(&SS + ((uVar8 >> 0x18) + 0x300) * 4);
  ks->data[5] = *(uint *)(&SS + ((uVar17 * 0x10000 >> 0x18) + 0x100) * 4) ^
                uVar4 ^ *(uint *)(&SS + (uVar17 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar17 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = *(uint *)(&SS + (uVar2 & 0xff) * 4);
  uVar17 = (uVar5 >> 8) << 0x18 | uVar15 >> 8;
  uVar5 = *(uint *)(&SS + (uVar8 & 0xff) * 4);
  ks->data[6] = *(uint *)(&SS + (uVar9 & 0xff) * 4) ^ uVar18 ^
                *(uint *)(&SS + ((uVar9 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar9 * 0x100 >> 0x18) + 0x200) * 4);
  uVar4 = *(uint *)(&SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar2 = *(uint *)(&SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[8] = *(uint *)(&SS + ((uVar8 * 0x100 >> 0x18) + 0x200) * 4) ^
                uVar3 ^ uVar5 ^ *(uint *)(&SS + ((uVar8 * 0x10000 >> 0x18) + 0x100) * 4);
  ks->data[7] = uVar1 ^ uVar16 ^ uVar4 ^ uVar2;
  uVar11 = uVar11 + 0x3910c8cd + uVar15;
  uVar18 = (uVar12 << 8) >> 0x18 | uVar6 << 8;
  uVar4 = (-0x3910c8cd - uVar12) + uVar19;
  uVar5 = uVar15 + uVar6 + 0x72219199;
  uVar1 = (uVar19 + 0x8dde6e67) - uVar10;
  uVar9 = uVar6 + 0xe4432331 + uVar17;
  uVar16 = (uVar19 >> 8) << 0x18 | uVar17 >> 8;
  uVar8 = (0x1bbcdccf - uVar10) + uVar14;
  uVar12 = (uVar10 << 8) >> 0x18 | uVar18 << 8;
  uVar3 = (uVar15 >> 8) << 0x18 | uVar14 >> 8;
  ks->data[9] = *(uint *)(&SS + (uVar7 & 0xff) * 4) ^ *(uint *)(&SS + ((uVar7 >> 0x18) + 0x300) * 4)
                ^ *(uint *)(&SS + ((uVar7 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar7 * 0x100 >> 0x18) + 0x200) * 4);
  uVar2 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4);
  ks->data[10] = *(uint *)(&SS + (uVar11 & 0xff) * 4) ^
                 *(uint *)(&SS + ((uVar11 >> 0x18) + 0x300) * 4) ^
                 *(uint *)(&SS + ((uVar11 * 0x10000 >> 0x18) + 0x100) * 4) ^
                 *(uint *)(&SS + ((uVar11 * 0x100 >> 0x18) + 0x200) * 4);
  uVar7 = *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4);
  uVar10 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4);
  uVar11 = *(uint *)(&SS + ((uVar9 >> 0x18) + 0x300) * 4);
  ks->data[0xb] =
       *(uint *)(&SS + (uVar4 & 0xff) * 4) ^ uVar2 ^
       *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar15 = *(uint *)(&SS + ((uVar8 >> 0x18) + 0x300) * 4);
  uVar6 = (uVar6 << 8) >> 0x18 | uVar13 << 8;
  ks->data[0xc] =
       *(uint *)(&SS + (uVar5 & 0xff) * 4) ^ uVar7 ^
       *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4);
  uVar2 = *(uint *)(&SS + (uVar9 & 0xff) * 4);
  uVar7 = *(uint *)(&SS + (uVar8 & 0xff) * 4);
  ks->data[0xd] =
       *(uint *)(&SS + (uVar1 & 0xff) * 4) ^ uVar10 ^
       *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = *(uint *)(&SS + ((uVar8 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar18 + 0x910c8cc4 + uVar16;
  uVar5 = (0x6ef3733c - uVar13) + uVar3;
  uVar8 = *(uint *)(&SS + ((uVar8 * 0x100 >> 0x18) + 0x200) * 4);
  uVar10 = (uVar14 + 0x3779b99e) - uVar13;
  uVar19 = (uVar17 >> 8) << 0x18 | uVar3 >> 8;
  ks->data[0xe] =
       uVar2 ^ uVar11 ^ *(uint *)(&SS + ((uVar9 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar9 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0xf] = uVar7 ^ uVar15 ^ uVar1 ^ uVar8;
  uVar1 = uVar17 + uVar18 + 0xc8864662;
  uVar15 = (uVar18 << 8) >> 0x18 | uVar6 << 8;
  uVar2 = (uVar3 + 0xdde6e678) - uVar6;
  uVar9 = *(uint *)(&SS + ((uVar10 >> 0x18) + 0x300) * 4);
  uVar11 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4);
  uVar18 = (uVar14 >> 8) << 0x18 | uVar16 >> 8;
  uVar7 = uVar16 + uVar12 + 0x22191988;
  uVar8 = (uVar13 << 8) >> 0x18 | uVar12 << 8;
  ks->data[0x10] =
       *(uint *)(&SS + (uVar1 & 0xff) * 4) ^ *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
       *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar13 = *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4);
  uVar14 = *(uint *)(&SS + ((uVar7 >> 0x18) + 0x300) * 4);
  ks->data[0x11] =
       *(uint *)(&SS + (uVar10 & 0xff) * 4) ^ uVar9 ^
       *(uint *)(&SS + ((uVar10 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar10 * 0x100 >> 0x18) + 0x200) * 4);
  uVar9 = (uVar3 >> 8) << 0x18 | uVar18 >> 8;
  uVar20 = *(uint *)(&SS + ((uVar2 >> 0x18) + 0x300) * 4);
  uVar17 = (uVar6 << 8) >> 0x18 | uVar8 << 8;
  ks->data[0x12] =
       *(uint *)(&SS + (uVar4 & 0xff) * 4) ^ uVar11 ^
       *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = *(uint *)(&SS + (uVar7 & 0xff) * 4);
  uVar3 = *(uint *)(&SS + (uVar2 & 0xff) * 4);
  ks->data[0x13] =
       *(uint *)(&SS + (uVar5 & 0xff) * 4) ^ uVar13 ^
       *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4);
  uVar11 = (uVar16 >> 8) << 0x18 | uVar19 >> 8;
  uVar4 = *(uint *)(&SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar2 = *(uint *)(&SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x14] =
       uVar1 ^ uVar14 ^ *(uint *)(&SS + ((uVar7 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar7 * 0x100 >> 0x18) + 0x200) * 4);
  uVar10 = uVar12 + 0x4432330f + uVar18;
  uVar13 = (-0x4432330f - uVar6) + uVar19;
  uVar5 = (uVar19 + 0x779b99e3) - uVar15;
  uVar1 = uVar8 + 0x10c8cc3a + uVar9;
  uVar14 = *(uint *)(&SS + ((uVar10 >> 0x18) + 0x300) * 4);
  ks->data[0x15] = uVar3 ^ uVar20 ^ uVar4 ^ uVar2;
  uVar6 = uVar18 + uVar8 + 0x8864661d;
  uVar7 = (uVar12 << 8) >> 0x18 | uVar15 << 8;
  uVar8 = uVar9 + uVar17 + 0x21919873;
  uVar3 = (uVar11 + 0xde6e678d) - uVar7;
  uVar20 = *(uint *)(&SS + (uVar13 & 0xff) * 4);
  uVar12 = *(uint *)(&SS + ((uVar13 >> 0x18) + 0x300) * 4);
  uVar2 = (-0x10c8cc3a - uVar15) + uVar11;
  ks->data[0x16] =
       *(uint *)(&SS + (uVar10 & 0xff) * 4) ^ uVar14 ^
       *(uint *)(&SS + ((uVar10 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar10 * 0x100 >> 0x18) + 0x200) * 4);
  uVar14 = *(uint *)(&SS + ((uVar6 >> 0x18) + 0x300) * 4);
  uVar4 = *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4);
  uVar15 = *(uint *)(&SS + (uVar6 & 0xff) * 4);
  uVar16 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4);
  ks->data[0x17] =
       uVar20 ^ uVar12 ^ *(uint *)(&SS + ((uVar13 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar13 * 0x100 >> 0x18) + 0x200) * 4);
  uVar13 = *(uint *)(&SS + ((uVar2 >> 0x18) + 0x300) * 4);
  uVar10 = *(uint *)(&SS + (uVar5 & 0xff) * 4);
  ks->data[0x18] =
       uVar15 ^ uVar14 ^ *(uint *)(&SS + ((uVar6 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar6 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = *(uint *)(&SS + (uVar1 & 0xff) * 4);
  ks->data[0x19] =
       uVar10 ^ uVar4 ^ *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4);
  uVar10 = *(uint *)(&SS + (uVar2 & 0xff) * 4);
  uVar14 = *(uint *)(&SS + ((uVar8 >> 0x18) + 0x300) * 4);
  uVar4 = *(uint *)(&SS + (uVar8 & 0xff) * 4);
  ks->data[0x1a] =
       uVar6 ^ uVar16 ^ *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = *(uint *)(&SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar2 = *(uint *)(&SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4);
  uVar9 = ((uVar19 >> 8) << 0x18 | uVar9 >> 8) + uVar17 + 0x432330e5;
  uVar5 = ((uVar18 >> 8) << 0x18 | uVar11 >> 8) + (-0x432330e5 - uVar7);
  ks->data[0x1c] =
       uVar4 ^ uVar14 ^ *(uint *)(&SS + ((uVar8 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar8 * 0x100 >> 0x18) + 0x200) * 4);
  uVar11 = *(uint *)(&SS + (uVar3 & 0xff) * 4);
  uVar1 = *(uint *)(&SS + ((uVar3 >> 0x18) + 0x300) * 4);
  ks->data[0x1b] = uVar10 ^ uVar13 ^ uVar6 ^ uVar2;
  uVar10 = *(uint *)(&SS + (uVar9 & 0xff) * 4);
  uVar7 = *(uint *)(&SS + ((uVar9 >> 0x18) + 0x300) * 4);
  uVar8 = *(uint *)(&SS + (uVar5 & 0xff) * 4);
  uVar6 = *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4);
  uVar14 = *(uint *)(&SS + ((uVar9 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar13 = *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = *(uint *)(&SS + ((uVar9 * 0x100 >> 0x18) + 0x200) * 4);
  uVar2 = *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x1d] =
       uVar11 ^ uVar1 ^ *(uint *)(&SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x1e] = uVar10 ^ uVar7 ^ uVar14 ^ uVar4;
  ks->data[0x1f] = uVar6 ^ uVar8 ^ uVar13 ^ uVar2;
  return;
}

