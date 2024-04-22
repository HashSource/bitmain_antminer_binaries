
void Camellia_DecryptBlock_Rounds(int param_1,byte *param_2,int param_3,undefined *param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  puVar5 = (uint *)(param_3 + param_1 * 0x40);
  uVar9 = (((uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18) ^ (uint)param_2[3] |
          (uint)param_2[2] << 8) ^ *(uint *)(param_3 + param_1 * 0x40);
  uVar8 = (((uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18) ^ (uint)param_2[0xf] |
          (uint)param_2[0xe] << 8) ^ puVar5[3];
  uVar10 = (((uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18) ^ (uint)param_2[7] |
           (uint)param_2[6] << 8) ^ puVar5[1];
  uVar4 = (((uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18) ^ (uint)param_2[0xb] |
          (uint)param_2[10] << 8) ^ puVar5[2];
  puVar6 = puVar5;
  while( true ) {
    HintPreloadData(puVar6 + -0x12);
    HintPreloadData(puVar6 + -0x11);
    HintPreloadData(puVar6 + -0x14);
    HintPreloadData(puVar6 + -0x13);
    uVar11 = puVar6[-1] ^ uVar10;
    uVar12 = uVar9 ^ puVar6[-2];
    uVar12 = *(uint *)(DAT_001219b8 + ((uVar12 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar12 >> 0x18) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar12 << 8) >> 0x18) + 0x200) * 4);
    uVar11 = *(uint *)(DAT_001219b8 + (((uVar11 << 8) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001219b8 + ((uVar11 >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar11 & 0xff) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar11 << 0x10) >> 0x18) + 0x100) * 4) ^ uVar12;
    uVar4 = uVar4 ^ uVar11;
    uVar13 = uVar4 ^ puVar6[-4];
    uVar8 = uVar11 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar8;
    uVar11 = uVar8 ^ puVar6[-3];
    uVar12 = *(uint *)(DAT_001219b8 + ((uVar13 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar13 >> 0x18) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar13 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar13 << 8) >> 0x18) + 0x200) * 4);
    uVar11 = *(uint *)(DAT_001219b8 + (((uVar11 << 8) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar11 & 0xff) * 4) ^
             *(uint *)(DAT_001219b8 + ((uVar11 >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar11 << 0x10) >> 0x18) + 0x100) * 4) ^ uVar12;
    uVar13 = uVar10 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar11;
    uVar9 = uVar9 ^ uVar11;
    uVar10 = uVar13 ^ puVar6[-5];
    uVar11 = uVar9 ^ puVar6[-6];
    uVar11 = *(uint *)(DAT_001219b8 + ((uVar11 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar11 >> 0x18) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar11 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar11 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = *(uint *)(DAT_001219b8 + (uVar10 & 0xff) * 4) ^
             *(uint *)(DAT_001219b8 + ((uVar10 >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^ uVar11;
    uVar4 = uVar10 ^ uVar4;
    uVar12 = uVar4 ^ puVar6[-8];
    uVar8 = uVar10 ^ (uVar11 >> 8 | uVar11 << 0x18) ^ uVar8;
    uVar10 = uVar8 ^ puVar6[-7];
    uVar11 = *(uint *)(DAT_001219b8 + (((uVar12 << 8) >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar12 >> 0x18) * 4) ^
             *(uint *)(DAT_001219b8 + ((uVar12 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4);
    uVar10 = *(uint *)(DAT_001219b8 + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar10 & 0xff) * 4) ^
             *(uint *)(DAT_001219b8 + ((uVar10 >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^ uVar11;
    uVar13 = uVar13 ^ (uVar11 >> 8 | uVar11 << 0x18) ^ uVar10;
    uVar9 = uVar9 ^ uVar10;
    uVar10 = uVar13 ^ puVar6[-9];
    uVar11 = uVar9 ^ puVar6[-10];
    uVar11 = *(uint *)(DAT_001219b8 + (((uVar11 << 8) >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001219b8 + ((uVar11 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar11 >> 0x18) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar11 << 0x10) >> 0x18) + 0x300) * 4);
    uVar10 = *(uint *)(DAT_001219b8 + (uVar10 & 0xff) * 4) ^
             *(uint *)(DAT_001219b8 + ((uVar10 >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^ uVar11;
    uVar4 = uVar10 ^ uVar4;
    uVar12 = uVar4 ^ puVar6[-0xc];
    uVar8 = uVar10 ^ (uVar11 >> 8 | uVar11 << 0x18) ^ uVar8;
    uVar10 = uVar8 ^ puVar6[-0xb];
    uVar11 = *(uint *)(DAT_001219b8 + ((uVar12 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (uVar12 >> 0x18) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar12 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = *(uint *)(DAT_001219b8 + (uVar10 & 0xff) * 4) ^
             *(uint *)(DAT_001219b8 + ((uVar10 >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(DAT_001219b8 + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^ uVar11;
    uVar9 = uVar10 ^ uVar9;
    uVar10 = uVar13 ^ (uVar11 >> 8 | uVar11 << 0x18) ^ uVar10;
    if ((uint *)(param_3 + 0x10) == puVar6 + -0xc) break;
    puVar1 = puVar6 + -0xe;
    puVar2 = puVar6 + -0xf;
    puVar3 = puVar6 + -0xd;
    puVar6 = puVar6 + -0x10;
    uVar10 = uVar10 ^ ((*puVar1 & uVar9) >> 0x1f | (*puVar1 & uVar9) << 1);
    uVar4 = (uVar8 | *puVar2) ^ uVar4;
    uVar8 = uVar8 ^ ((uVar4 & *puVar6) >> 0x1f | (uVar4 & *puVar6) << 1);
    uVar9 = uVar9 ^ (uVar10 | *puVar3);
  }
  uVar13 = (int)puVar5 + (-0x40 - param_3) & 0xffffffc0;
  uVar11 = *(uint *)((int)puVar5 + (-0x3c - uVar13));
  uVar12 = *(uint *)((int)puVar5 + (-0x38 - uVar13));
  uVar7 = *(uint *)((int)puVar5 + (-0x34 - uVar13));
  uVar4 = uVar4 ^ *(uint *)((int)puVar5 + (-0x40 - uVar13));
  param_4[3] = (char)uVar4;
  uVar8 = uVar8 ^ uVar11;
  *param_4 = (char)(uVar4 >> 0x18);
  uVar9 = uVar9 ^ uVar12;
  uVar10 = uVar10 ^ uVar7;
  param_4[7] = (char)uVar8;
  param_4[0xb] = (char)uVar9;
  param_4[0xf] = (char)uVar10;
  param_4[1] = (char)(uVar4 >> 0x10);
  param_4[2] = (char)(uVar4 >> 8);
  param_4[4] = (char)(uVar8 >> 0x18);
  param_4[5] = (char)(uVar8 >> 0x10);
  param_4[6] = (char)(uVar8 >> 8);
  param_4[8] = (char)(uVar9 >> 0x18);
  param_4[9] = (char)(uVar9 >> 0x10);
  param_4[10] = (char)(uVar9 >> 8);
  param_4[0xc] = (char)(uVar10 >> 0x18);
  param_4[0xd] = (char)(uVar10 >> 0x10);
  param_4[0xe] = (char)(uVar10 >> 8);
  return;
}

