
void Camellia_EncryptBlock_Rounds(int param_1,byte *param_2,uint *param_3,undefined *param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_38;
  uint *local_34;
  
  puVar4 = param_3 + 4;
  local_34 = param_3 + 0x14;
  uVar7 = (uint)param_2[3] ^ *param_3 ^ (uint)*param_2 << 0x18 ^ (uint)param_2[1] << 0x10 ^
          (uint)param_2[2] << 8;
  local_38 = param_3[3] ^ (uint)param_2[0xf] ^ (uint)param_2[0xc] << 0x18 ^
             (uint)param_2[0xd] << 0x10 ^ (uint)param_2[0xe] << 8;
  uVar3 = (uint)param_2[0xb] ^ param_3[2] ^ (uint)param_2[8] << 0x18 ^ (uint)param_2[9] << 0x10 ^
          (uint)param_2[10] << 8;
  uVar8 = (uint)param_2[7] ^ param_3[1] ^ (uint)param_2[4] << 0x18 ^ (uint)param_2[5] << 0x10 ^
          (uint)param_2[6] << 8;
  puVar5 = puVar4;
  while( true ) {
    HintPreloadData(puVar5 + 0x11);
    HintPreloadData(puVar5 + 0x12);
    HintPreloadData(puVar5 + 0x13);
    puVar1 = local_34 + -0x10;
    HintPreloadData(local_34);
    uVar11 = uVar8 ^ puVar5[1];
    local_34 = local_34 + 0x10;
    uVar9 = uVar7 ^ *puVar1;
    uVar10 = *(uint *)(DAT_001214f0 + ((uVar9 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_001214f0 + (uVar9 >> 0x18) * 4) ^
             *(uint *)(DAT_001214f0 + (((uVar9 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001214f0 + (((uVar9 << 8) >> 0x18) + 0x200) * 4);
    uVar9 = *(uint *)(DAT_001214f0 + (uVar11 & 0xff) * 4) ^
            *(uint *)(DAT_001214f0 + ((uVar11 >> 0x18) + 0x200) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar11 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar11 << 8) >> 0x18) + 0x300) * 4) ^ uVar10;
    uVar3 = uVar9 ^ uVar3;
    uVar11 = uVar3 ^ puVar5[2];
    local_38 = uVar9 ^ (uVar10 >> 8 | uVar10 << 0x18) ^ local_38;
    uVar10 = local_38 ^ puVar5[3];
    uVar9 = *(uint *)(DAT_001214f0 + ((uVar11 & 0xff) + 0x100) * 4) ^
            *(uint *)(DAT_001214f0 + (uVar11 >> 0x18) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar11 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar11 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = *(uint *)(DAT_001214f0 + (uVar10 & 0xff) * 4) ^
             *(uint *)(DAT_001214f0 + ((uVar10 >> 0x18) + 0x200) * 4) ^
             *(uint *)(DAT_001214f0 + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(DAT_001214f0 + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^ uVar9;
    uVar9 = uVar8 ^ (uVar9 >> 8 | uVar9 << 0x18) ^ uVar10;
    uVar10 = uVar10 ^ uVar7;
    uVar7 = uVar9 ^ puVar5[5];
    uVar8 = uVar10 ^ puVar5[4];
    uVar11 = *(uint *)(DAT_001214f0 + ((uVar8 & 0xff) + 0x100) * 4) ^
             *(uint *)(DAT_001214f0 + (uVar8 >> 0x18) * 4) ^
             *(uint *)(DAT_001214f0 + (((uVar8 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(DAT_001214f0 + (((uVar8 << 8) >> 0x18) + 0x200) * 4);
    uVar8 = *(uint *)(DAT_001214f0 + ((uVar7 >> 0x18) + 0x200) * 4) ^
            *(uint *)(DAT_001214f0 + (uVar7 & 0xff) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar7 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar7 << 8) >> 0x18) + 0x300) * 4) ^ uVar11;
    uVar3 = uVar8 ^ uVar3;
    uVar7 = uVar3 ^ puVar5[6];
    local_38 = uVar8 ^ (uVar11 >> 8 | uVar11 << 0x18) ^ local_38;
    uVar8 = local_38 ^ puVar5[7];
    uVar7 = *(uint *)(DAT_001214f0 + (uVar7 >> 0x18) * 4) ^
            *(uint *)(DAT_001214f0 + ((uVar7 & 0xff) + 0x100) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar7 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar7 << 8) >> 0x18) + 0x200) * 4);
    uVar11 = uVar7 ^ *(uint *)(DAT_001214f0 + (uVar8 & 0xff) * 4) ^
                     *(uint *)(DAT_001214f0 + ((uVar8 >> 0x18) + 0x200) * 4) ^
                     *(uint *)(DAT_001214f0 + (((uVar8 << 0x10) >> 0x18) + 0x100) * 4) ^
                     *(uint *)(DAT_001214f0 + (((uVar8 << 8) >> 0x18) + 0x300) * 4);
    uVar10 = uVar10 ^ uVar11;
    uVar11 = uVar9 ^ (uVar7 >> 8 | uVar7 << 0x18) ^ uVar11;
    uVar8 = puVar5[9] ^ uVar11;
    uVar7 = uVar10 ^ puVar5[8];
    uVar7 = *(uint *)(DAT_001214f0 + ((uVar7 & 0xff) + 0x100) * 4) ^
            *(uint *)(DAT_001214f0 + (uVar7 >> 0x18) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar7 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar7 << 8) >> 0x18) + 0x200) * 4);
    uVar9 = *(uint *)(DAT_001214f0 + (((uVar8 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(DAT_001214f0 + ((uVar8 >> 0x18) + 0x200) * 4) ^
            *(uint *)(DAT_001214f0 + (uVar8 & 0xff) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar8 << 8) >> 0x18) + 0x300) * 4) ^ uVar7;
    uVar3 = uVar9 ^ uVar3;
    uVar8 = uVar3 ^ puVar5[10];
    local_38 = uVar9 ^ (uVar7 >> 8 | uVar7 << 0x18) ^ local_38;
    uVar7 = local_38 ^ puVar5[0xb];
    uVar9 = *(uint *)(DAT_001214f0 + ((uVar8 & 0xff) + 0x100) * 4) ^
            *(uint *)(DAT_001214f0 + (uVar8 >> 0x18) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar8 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar8 << 8) >> 0x18) + 0x200) * 4);
    uVar8 = *(uint *)(DAT_001214f0 + (uVar7 & 0xff) * 4) ^
            *(uint *)(DAT_001214f0 + ((uVar7 >> 0x18) + 0x200) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar7 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(DAT_001214f0 + (((uVar7 << 8) >> 0x18) + 0x300) * 4) ^ uVar9;
    uVar10 = uVar8 ^ uVar10;
    uVar8 = uVar11 ^ (uVar9 >> 8 | uVar9 << 0x18) ^ uVar8;
    if (param_3 + param_1 * 0x10 == puVar5 + 0xc) break;
    puVar1 = puVar5 + 0xe;
    uVar8 = uVar8 ^ ((puVar5[0xc] & uVar10) >> 0x1f | (puVar5[0xc] & uVar10) << 1);
    puVar2 = puVar5 + 0xd;
    uVar3 = (local_38 | puVar5[0xf]) ^ uVar3;
    puVar5 = puVar5 + 0x10;
    local_38 = local_38 ^ ((uVar3 & *puVar1) >> 0x1f | (uVar3 & *puVar1) << 1);
    uVar7 = uVar10 ^ (uVar8 | *puVar2);
  }
  uVar11 = (int)(param_3 + param_1 * 0x10) - (int)(param_3 + 0x10) & 0xffffffc0;
  uVar7 = *(uint *)((int)puVar4 + uVar11 + 0x34);
  uVar9 = *(uint *)((int)puVar4 + uVar11 + 0x38);
  uVar6 = *(uint *)((int)puVar4 + uVar11 + 0x3c);
  uVar3 = *(uint *)((int)puVar4 + uVar11 + 0x30) ^ uVar3;
  param_4[3] = (char)uVar3;
  local_38 = local_38 ^ uVar7;
  *param_4 = (char)(uVar3 >> 0x18);
  uVar10 = uVar10 ^ uVar9;
  uVar8 = uVar8 ^ uVar6;
  param_4[7] = (char)local_38;
  param_4[0xb] = (char)uVar10;
  param_4[0xf] = (char)uVar8;
  param_4[1] = (char)(uVar3 >> 0x10);
  param_4[2] = (char)(uVar3 >> 8);
  param_4[4] = (char)(local_38 >> 0x18);
  param_4[5] = (char)(local_38 >> 0x10);
  param_4[6] = (char)(local_38 >> 8);
  param_4[8] = (char)(uVar10 >> 0x18);
  param_4[9] = (char)(uVar10 >> 0x10);
  param_4[10] = (char)(uVar10 >> 8);
  param_4[0xc] = (char)(uVar8 >> 0x18);
  param_4[0xd] = (char)(uVar8 >> 0x10);
  param_4[0xe] = (char)(uVar8 >> 8);
  return;
}

