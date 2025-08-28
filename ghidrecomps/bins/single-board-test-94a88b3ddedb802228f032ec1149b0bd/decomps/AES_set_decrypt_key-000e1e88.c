
int AES_set_decrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  AES_KEY *pAVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iStack_40;
  AES_KEY *pAStack_34;
  
  iVar1 = private_AES_set_encrypt_key(userKey,bits,key);
  if (-1 < iVar1) {
    iVar1 = key->rounds;
    if (0 < iVar1 * 4) {
      puVar5 = key->rd_key + iVar1 * 4;
      puVar8 = key->rd_key + iVar1 * 4 + 1;
      puVar2 = key->rd_key + 1;
      iVar3 = 0;
      pAVar7 = key;
      do {
        uVar10 = ((AES_KEY *)(puVar2 + -1))->rd_key[0];
        iVar3 = iVar3 + 4;
        ((AES_KEY *)(puVar2 + -1))->rd_key[0] = puVar8[-1];
        puVar2 = puVar2 + 4;
        puVar8[-1] = uVar10;
        puVar8 = puVar8 + -4;
        uVar10 = pAVar7->rd_key[1];
        pAVar7->rd_key[1] = puVar5[1];
        puVar5[1] = uVar10;
        uVar10 = pAVar7->rd_key[2];
        pAVar7->rd_key[2] = puVar5[2];
        puVar5[2] = uVar10;
        uVar10 = pAVar7->rd_key[3];
        pAVar7->rd_key[3] = puVar5[3];
        pAVar7 = (AES_KEY *)(pAVar7->rd_key + 4);
        puVar5[3] = uVar10;
        puVar5 = puVar5 + -4;
      } while (iVar3 < iVar1 * 4 - iVar3);
    }
    if (1 < iVar1) {
      iStack_40 = 1;
      pAVar7 = key;
      pAStack_34 = key;
      do {
        uVar10 = pAStack_34->rd_key[4];
        iStack_40 = iStack_40 + 1;
        pAStack_34 = (AES_KEY *)(pAStack_34->rd_key + 4);
        pAStack_34->rd_key[0] =
             *(uint *)(Td0 + (uint)(byte)Te1[(uVar10 >> 0x18) * 4] * 4) ^
             *(uint *)(Td3 + (uint)(byte)Te1[(uVar10 & 0xff) * 4] * 4) ^
             *(uint *)(Td1 + (uint)(byte)Te1[((uVar10 << 8) >> 0x18) * 4] * 4) ^
             *(uint *)(Td2 + (uint)(byte)Te1[((uVar10 << 0x10) >> 0x18) * 4] * 4);
        uVar11 = pAVar7->rd_key[5];
        uVar4 = pAVar7->rd_key[6];
        uVar10 = pAVar7->rd_key[7];
        uVar12 = *(uint *)(Td3 + (uint)(byte)Te1[(uVar11 & 0xff) * 4] * 4);
        uVar14 = *(uint *)(Td0 + (uint)(byte)Te1[(uVar11 >> 0x18) * 4] * 4);
        uVar13 = *(uint *)(Td1 + (uint)(byte)Te1[((uVar11 << 8) >> 0x18) * 4] * 4);
        uVar9 = *(uint *)(Td3 + (uint)(byte)Te1[(uVar10 & 0xff) * 4] * 4);
        uVar16 = *(uint *)(Td0 + (uint)(byte)Te1[(uVar10 >> 0x18) * 4] * 4);
        uVar15 = *(uint *)(Td1 + (uint)(byte)Te1[((uVar10 << 8) >> 0x18) * 4] * 4);
        uVar6 = *(uint *)(Td2 + (uint)(byte)Te1[((uVar10 << 0x10) >> 0x18) * 4] * 4);
        uVar10 = *(uint *)(Td2 + (uint)(byte)Te1[((uVar11 << 0x10) >> 0x18) * 4] * 4);
        pAVar7->rd_key[6] =
             *(uint *)(Td0 + (uint)(byte)Te1[(uVar4 >> 0x18) * 4] * 4) ^
             *(uint *)(Td3 + (uint)(byte)Te1[(uVar4 & 0xff) * 4] * 4) ^
             *(uint *)(Td1 + (uint)(byte)Te1[((uVar4 << 8) >> 0x18) * 4] * 4) ^
             *(uint *)(Td2 + (uint)(byte)Te1[((uVar4 << 0x10) >> 0x18) * 4] * 4);
        pAVar7->rd_key[7] = uVar9 ^ uVar16 ^ uVar15 ^ uVar6;
        pAVar7->rd_key[5] = uVar12 ^ uVar14 ^ uVar13 ^ uVar10;
        pAVar7 = (AES_KEY *)(pAVar7->rd_key + 4);
      } while (iStack_40 < key->rounds);
    }
    iVar1 = 0;
  }
  return iVar1;
}

