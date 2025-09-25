
void Camellia_DecryptBlock_Rounds(int param_1,byte *param_2,int param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar4 = param_3 + param_1 * 0x40;
  uVar7 = (((uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18) ^ (uint)param_2[3] |
          (uint)param_2[2] << 8) ^ *(uint *)(param_3 + param_1 * 0x40);
  uVar9 = (((uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18) ^ (uint)param_2[0xb] |
          (uint)param_2[10] << 8) ^ *(uint *)(iVar4 + 8);
  uVar3 = *(uint *)(iVar4 + 4) ^
          (((uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18) ^ (uint)param_2[7] |
          (uint)param_2[6] << 8);
  uVar8 = (((uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18) ^ (uint)param_2[0xf] |
          (uint)param_2[0xe] << 8) ^ *(uint *)(iVar4 + 0xc);
  iVar5 = iVar4 + -0x48;
  while( true ) {
    HintPreloadData(iVar5);
    uVar1 = uVar7 ^ *(uint *)(iVar5 + 0x40);
    HintPreloadData(iVar5 + 4);
    uVar2 = *(uint *)(iVar5 + 0x44) ^ uVar3;
    HintPreloadData(iVar5 + -8);
    HintPreloadData(iVar5 + -4);
    uVar6 = *(uint *)(&Camellia_SBOX + ((uVar1 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar1 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar1 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
    uVar2 = *(uint *)(&Camellia_SBOX + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar2 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 8) >> 0x18) + 0x300) * 4) ^ uVar6;
    uVar9 = uVar9 ^ uVar2;
    uVar1 = uVar9 ^ *(uint *)(iVar5 + 0x38);
    uVar8 = uVar2 ^ (uVar6 >> 8 | uVar6 << 0x18) ^ uVar8;
    uVar6 = uVar8 ^ *(uint *)(iVar5 + 0x3c);
    uVar2 = *(uint *)(&Camellia_SBOX + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar1 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar1 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar1 << 0x10) >> 0x18) + 0x300) * 4);
    uVar1 = uVar2 ^ *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4);
    uVar7 = uVar7 ^ uVar1;
    uVar1 = uVar3 ^ (uVar2 >> 8 | uVar2 << 0x18) ^ uVar1;
    uVar3 = uVar7 ^ *(uint *)(iVar5 + 0x30);
    uVar2 = *(uint *)(iVar5 + 0x34) ^ uVar1;
    uVar6 = *(uint *)(&Camellia_SBOX + ((uVar3 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
    uVar2 = *(uint *)(&Camellia_SBOX + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar2 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 8) >> 0x18) + 0x300) * 4) ^ uVar6;
    uVar9 = uVar9 ^ uVar2;
    uVar3 = *(uint *)(iVar5 + 0x28) ^ uVar9;
    uVar8 = uVar2 ^ (uVar6 >> 8 | uVar6 << 0x18) ^ uVar8;
    uVar2 = uVar8 ^ *(uint *)(iVar5 + 0x2c);
    uVar3 = *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar3 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
    uVar2 = uVar3 ^ *(uint *)(&Camellia_SBOX + (uVar2 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar2 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar2 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar2 << 8) >> 0x18) + 0x300) * 4);
    uVar7 = uVar7 ^ uVar2;
    uVar2 = uVar1 ^ (uVar3 >> 8 | uVar3 << 0x18) ^ uVar2;
    uVar3 = uVar7 ^ *(uint *)(iVar5 + 0x20);
    uVar1 = *(uint *)(iVar5 + 0x24) ^ uVar2;
    uVar6 = *(uint *)(&Camellia_SBOX + ((uVar3 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
    uVar1 = uVar6 ^ *(uint *)(&Camellia_SBOX + (uVar1 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar1 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar1 << 8) >> 0x18) + 0x300) * 4);
    uVar9 = uVar9 ^ uVar1;
    uVar3 = uVar9 ^ *(uint *)(iVar5 + 0x18);
    uVar8 = uVar1 ^ (uVar6 >> 8 | uVar6 << 0x18) ^ uVar8;
    uVar6 = uVar8 ^ *(uint *)(iVar5 + 0x1c);
    uVar1 = *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar3 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4);
    uVar3 = *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4) ^ uVar1;
    uVar7 = uVar7 ^ uVar3;
    uVar3 = uVar3 ^ uVar2 ^ (uVar1 >> 8 | uVar1 << 0x18);
    if (param_3 + 0x10 == iVar5 + 0x18) break;
    uVar1 = uVar7 & *(uint *)(iVar5 + 0x10);
    uVar3 = uVar3 ^ (uVar1 >> 0x1f | uVar1 << 1);
    uVar9 = (uVar8 | *(uint *)(iVar5 + 0xc)) ^ uVar9;
    uVar1 = uVar9 & *(uint *)(iVar5 + 8);
    uVar8 = uVar8 ^ (uVar1 >> 0x1f | uVar1 << 1);
    uVar7 = (*(uint *)(iVar5 + 0x14) | uVar3) ^ uVar7;
    iVar5 = iVar5 + -0x40;
  }
  iVar4 = iVar4 - ((iVar4 - param_3) - 0x40U & 0xffffffc0);
  uVar1 = *(uint *)(iVar4 + -0x3c);
  uVar2 = *(uint *)(iVar4 + -0x38);
  uVar6 = *(uint *)(iVar4 + -0x34);
  uVar9 = uVar9 ^ *(uint *)(iVar4 + -0x40);
  param_4[3] = (char)uVar9;
  uVar8 = uVar8 ^ uVar1;
  uVar7 = uVar7 ^ uVar2;
  uVar6 = uVar6 ^ uVar3;
  *param_4 = (char)(uVar9 >> 0x18);
  param_4[0xb] = (char)uVar7;
  param_4[0xf] = (char)uVar6;
  param_4[2] = (char)(uVar9 >> 8);
  param_4[4] = (char)(uVar8 >> 0x18);
  param_4[7] = (char)uVar8;
  param_4[1] = (char)(uVar9 >> 0x10);
  param_4[5] = (char)(uVar8 >> 0x10);
  param_4[6] = (char)(uVar8 >> 8);
  param_4[8] = (char)(uVar7 >> 0x18);
  param_4[9] = (char)(uVar7 >> 0x10);
  param_4[10] = (char)(uVar7 >> 8);
  param_4[0xc] = (char)(uVar6 >> 0x18);
  param_4[0xd] = (char)(uVar6 >> 0x10);
  param_4[0xe] = (char)(uVar6 >> 8);
  return;
}

