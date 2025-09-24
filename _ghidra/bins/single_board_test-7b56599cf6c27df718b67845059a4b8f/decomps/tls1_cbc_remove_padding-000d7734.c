
uint tls1_cbc_remove_padding(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  EVP_CIPHER *cipher;
  ulong uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  
  uVar9 = param_4 + 1;
  uVar7 = *(uint *)(param_2 + 8);
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) & 1) == 0) {
    if (uVar7 < uVar9) {
      return 0;
    }
    iVar5 = *(int *)(param_2 + 0x14);
  }
  else {
    if (uVar7 < uVar9 + param_3) {
      return 0;
    }
    uVar7 = uVar7 - param_3;
    iVar5 = *(int *)(param_2 + 0x14) + param_3;
    *(uint *)(param_2 + 8) = uVar7;
    *(int *)(param_2 + 0x14) = iVar5;
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + param_3;
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) - param_3;
  }
  bVar1 = *(byte *)(uVar7 + iVar5 + -1);
  uVar7 = (uint)bVar1;
  cipher = EVP_CIPHER_CTX_cipher(*(EVP_CIPHER_CTX **)(param_1 + 0x3cc));
  uVar2 = EVP_CIPHER_flags(cipher);
  if ((int)(uVar2 << 10) < 0) {
    *(uint *)(param_2 + 8) = (*(int *)(param_2 + 8) + -1) - uVar7;
    return 1;
  }
  uVar12 = *(uint *)(param_2 + 8);
  uVar9 = uVar9 + uVar7;
  uVar9 = ~((int)((uVar9 ^ uVar12 - uVar9 | uVar12 ^ uVar9) ^ uVar12) >> 0x1f);
  bVar4 = (byte)uVar9;
  if (uVar12 < 0x100) {
    uVar11 = uVar12;
    if (uVar12 == 0) goto LAB_000d77d2;
  }
  else {
    uVar11 = 0x100;
  }
  uVar6 = 0;
  pbVar10 = (byte *)(*(int *)(param_2 + 0x14) + uVar12);
  do {
    pbVar10 = pbVar10 + -1;
    uVar8 = uVar7 - uVar6 ^ uVar6;
    uVar3 = uVar7 ^ uVar6;
    uVar6 = uVar6 + 1;
    uVar9 = uVar9 & ~((uint)(*pbVar10 ^ bVar1) & ~((int)((uVar3 | uVar8) ^ uVar7) >> 0x1f));
    bVar4 = (byte)uVar9;
  } while (uVar6 < uVar11);
LAB_000d77d2:
  uVar9 = (int)((bVar4 ^ 0xff) - 1 & ~(bVar4 ^ 0xff)) >> 0x1f;
  *(uint *)(param_2 + 8) = uVar12 - (uVar7 + 1 & uVar9);
  return ~uVar9 | uVar9 & 1;
}

