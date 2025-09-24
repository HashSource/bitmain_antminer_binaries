
void Camellia_EncryptBlock_Rounds(int param_1,byte *param_2,uint *param_3,undefined1 *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  
  puVar1 = param_3 + param_1 * 0x10;
  uVar9 = (((uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18) ^ (uint)param_2[3] |
          (uint)param_2[2] << 8) ^ *param_3;
  uVar6 = param_3[1] ^
          ((uint)param_2[7] ^ ((uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18) |
          (uint)param_2[6] << 8);
  uVar7 = param_3[2] ^
          ((uint)param_2[0xb] ^ ((uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18) |
          (uint)param_2[10] << 8);
  uVar2 = (((uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18) ^ (uint)param_2[0xf] |
          (uint)param_2[0xe] << 8) ^ param_3[3];
  puVar8 = param_3 + 0x14;
  while( true ) {
    uVar3 = uVar9 ^ puVar8[-0x10];
    HintPreloadData(puVar8);
    HintPreloadData(puVar8 + 1);
    uVar4 = puVar8[-0xf] ^ uVar6;
    HintPreloadData(puVar8 + 2);
    HintPreloadData(puVar8 + 3);
    uVar5 = *(uint *)(&Camellia_SBOX + ((uVar3 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
    uVar3 = *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar4 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x300) * 4) ^ uVar5;
    uVar7 = uVar7 ^ uVar3;
    uVar2 = uVar2 ^ uVar3 ^ (uVar5 >> 8 | uVar5 << 0x18);
    uVar4 = puVar8[-0xd] ^ uVar2;
    uVar3 = uVar7 ^ puVar8[-0xe];
    uVar10 = *(uint *)(&Camellia_SBOX + ((uVar3 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
    uVar5 = uVar10 ^ *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
                     *(uint *)(&Camellia_SBOX + ((uVar4 >> 0x18) + 0x200) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x300) * 4);
    uVar9 = uVar9 ^ uVar5;
    uVar3 = uVar9 ^ puVar8[-0xc];
    uVar5 = uVar6 ^ (uVar10 >> 8 | uVar10 << 0x18) ^ uVar5;
    uVar6 = puVar8[-0xb] ^ uVar5;
    uVar3 = *(uint *)(&Camellia_SBOX + ((uVar3 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
    uVar6 = *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4) ^ uVar3;
    uVar7 = uVar6 ^ uVar7;
    uVar4 = uVar7 ^ puVar8[-10];
    uVar2 = uVar6 ^ (uVar3 >> 8 | uVar3 << 0x18) ^ uVar2;
    uVar6 = puVar8[-9] ^ uVar2;
    uVar10 = *(uint *)(&Camellia_SBOX + ((uVar4 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar4 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x200) * 4);
    uVar3 = uVar10 ^ *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
                     *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4);
    uVar9 = uVar9 ^ uVar3;
    uVar4 = uVar9 ^ puVar8[-8];
    uVar3 = uVar3 ^ uVar5 ^ (uVar10 >> 8 | uVar10 << 0x18);
    uVar6 = puVar8[-7] ^ uVar3;
    uVar4 = *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar4 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar4 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x300) * 4);
    uVar6 = *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4) ^ uVar4;
    uVar7 = uVar7 ^ uVar6;
    uVar5 = puVar8[-6] ^ uVar7;
    uVar2 = uVar2 ^ uVar6 ^ (uVar4 >> 8 | uVar4 << 0x18);
    uVar6 = puVar8[-5] ^ uVar2;
    uVar4 = *(uint *)(&Camellia_SBOX + (((uVar5 << 8) >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar5 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar5 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar5 << 0x10) >> 0x18) + 0x300) * 4);
    uVar6 = uVar4 ^ *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4);
    uVar9 = uVar9 ^ uVar6;
    uVar6 = uVar6 ^ uVar3 ^ (uVar4 >> 8 | uVar4 << 0x18);
    if (puVar1 == puVar8 + -4) break;
    uVar6 = uVar6 ^ ((uVar9 & puVar8[-4]) >> 0x1f | (uVar9 & puVar8[-4]) << 1);
    uVar7 = (puVar8[-1] | uVar2) ^ uVar7;
    uVar2 = uVar2 ^ ((puVar8[-2] & uVar7) >> 0x1f | (puVar8[-2] & uVar7) << 1);
    uVar9 = (uVar6 | puVar8[-3]) ^ uVar9;
    puVar8 = puVar8 + 0x10;
  }
  uVar7 = uVar7 ^ *puVar1;
  uVar6 = uVar6 ^ puVar1[3];
  uVar2 = uVar2 ^ puVar1[1];
  uVar9 = uVar9 ^ puVar1[2];
  *param_4 = (char)(uVar7 >> 0x18);
  param_4[3] = (char)uVar7;
  param_4[7] = (char)uVar2;
  param_4[0xb] = (char)uVar9;
  param_4[0xf] = (char)uVar6;
  param_4[2] = (char)(uVar7 >> 8);
  param_4[4] = (char)(uVar2 >> 0x18);
  param_4[1] = (char)(uVar7 >> 0x10);
  param_4[5] = (char)(uVar2 >> 0x10);
  param_4[6] = (char)(uVar2 >> 8);
  param_4[8] = (char)(uVar9 >> 0x18);
  param_4[9] = (char)(uVar9 >> 0x10);
  param_4[10] = (char)(uVar9 >> 8);
  param_4[0xc] = (char)(uVar6 >> 0x18);
  param_4[0xd] = (char)(uVar6 >> 0x10);
  param_4[0xe] = (char)(uVar6 >> 8);
  return;
}

