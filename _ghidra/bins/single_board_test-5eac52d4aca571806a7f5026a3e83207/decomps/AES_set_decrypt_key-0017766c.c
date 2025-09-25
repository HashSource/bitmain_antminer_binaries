
int AES_set_decrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  AES_KEY *pAVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int local_38;
  
  iVar5 = AES_set_encrypt_key(userKey,bits,key);
  if (-1 < iVar5) {
    iVar5 = key->rounds;
    if (0 < iVar5 * 4) {
      iVar7 = 0;
      pAVar9 = key;
      puVar10 = key->rd_key + iVar5 * 4;
      do {
        uVar11 = pAVar9->rd_key[0];
        iVar7 = iVar7 + 4;
        pAVar9->rd_key[0] = *puVar10;
        *puVar10 = uVar11;
        uVar11 = pAVar9->rd_key[1];
        pAVar9->rd_key[1] = puVar10[1];
        puVar10[1] = uVar11;
        uVar11 = pAVar9->rd_key[2];
        pAVar9->rd_key[2] = puVar10[2];
        puVar10[2] = uVar11;
        uVar11 = pAVar9->rd_key[3];
        pAVar9->rd_key[3] = puVar10[3];
        puVar10[3] = uVar11;
        pAVar9 = (AES_KEY *)(pAVar9->rd_key + 4);
        puVar10 = puVar10 + -4;
      } while (iVar7 < iVar5 * 4 - iVar7);
      iVar5 = key->rounds;
    }
    if (1 < iVar5) {
      local_38 = 1;
      pAVar9 = key;
      do {
        uVar13 = pAVar9->rd_key[4];
        uVar12 = pAVar9->rd_key[5];
        local_38 = local_38 + 1;
        uVar8 = pAVar9->rd_key[6];
        uVar17 = *(uint *)(Td0 + (uint)(byte)Te1[(uVar13 >> 0x18) * 4] * 4);
        uVar11 = *(uint *)(Td3 + (uint)(byte)Te1[(uVar12 & 0xff) * 4] * 4);
        uVar14 = *(uint *)(Td3 + (uint)(byte)Te1[(uVar13 & 0xff) * 4] * 4);
        uVar16 = *(uint *)(Td0 + (uint)(byte)Te1[(uVar12 >> 0x18) * 4] * 4);
        uVar18 = *(uint *)(Td1 + (uint)(byte)Te1[((uVar13 << 8) >> 0x18) * 4] * 4);
        uVar6 = pAVar9->rd_key[7];
        uVar15 = *(uint *)(Td1 + (uint)(byte)Te1[((uVar12 << 8) >> 0x18) * 4] * 4);
        uVar13 = *(uint *)(Td2 + (uint)(byte)Te1[((uVar13 << 0x10) >> 0x18) * 4] * 4);
        uVar12 = *(uint *)(Td2 + (uint)(byte)Te1[((uVar12 << 0x10) >> 0x18) * 4] * 4);
        pAVar9->rd_key[6] =
             *(uint *)(Td0 + (uint)(byte)Te1[(uVar8 >> 0x18) * 4] * 4) ^
             *(uint *)(Td3 + (uint)(byte)Te1[(uVar8 & 0xff) * 4] * 4) ^
             *(uint *)(Td1 + (uint)(byte)Te1[((uVar8 << 8) >> 0x18) * 4] * 4) ^
             *(uint *)(Td2 + (uint)(byte)Te1[((uVar8 << 0x10) >> 0x18) * 4] * 4);
        bVar1 = Te1[(uVar6 & 0xff) * 4];
        bVar2 = Te1[(uVar6 >> 0x18) * 4];
        ((AES_KEY *)(pAVar9->rd_key + 4))->rd_key[0] = uVar17 ^ uVar14 ^ uVar18 ^ uVar13;
        bVar3 = Te1[((uVar6 << 8) >> 0x18) * 4];
        bVar4 = Te1[((uVar6 << 0x10) >> 0x18) * 4];
        pAVar9->rd_key[5] = uVar16 ^ uVar11 ^ uVar15 ^ uVar12;
        pAVar9->rd_key[7] =
             *(uint *)(Td2 + (uint)bVar4 * 4) ^
             *(uint *)(Td1 + (uint)bVar3 * 4) ^
             *(uint *)(Td0 + (uint)bVar2 * 4) ^ *(uint *)(Td3 + (uint)bVar1 * 4);
        pAVar9 = (AES_KEY *)(pAVar9->rd_key + 4);
      } while (local_38 < key->rounds);
    }
    iVar5 = 0;
  }
  return iVar5;
}

