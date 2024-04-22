
int private_AES_set_decrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  AES_KEY *pAVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int local_40;
  AES_KEY *local_34;
  
  iVar2 = private_AES_set_encrypt_key(userKey,bits,key);
  if (-1 < iVar2) {
    iVar2 = key->rounds;
    if (0 < iVar2 * 4) {
      puVar6 = key->rd_key + iVar2 * 4;
      puVar9 = key->rd_key + iVar2 * 4 + 1;
      puVar3 = key->rd_key + 1;
      iVar4 = 0;
      pAVar8 = key;
      do {
        uVar11 = ((AES_KEY *)(puVar3 + -1))->rd_key[0];
        iVar4 = iVar4 + 4;
        ((AES_KEY *)(puVar3 + -1))->rd_key[0] = puVar9[-1];
        puVar3 = puVar3 + 4;
        puVar9[-1] = uVar11;
        puVar9 = puVar9 + -4;
        uVar11 = pAVar8->rd_key[1];
        pAVar8->rd_key[1] = puVar6[1];
        puVar6[1] = uVar11;
        uVar11 = pAVar8->rd_key[2];
        pAVar8->rd_key[2] = puVar6[2];
        puVar6[2] = uVar11;
        uVar11 = pAVar8->rd_key[3];
        pAVar8->rd_key[3] = puVar6[3];
        pAVar8 = (AES_KEY *)(pAVar8->rd_key + 4);
        puVar6[3] = uVar11;
        puVar6 = puVar6 + -4;
      } while (iVar4 < iVar2 * 4 - iVar4);
    }
    iVar1 = DAT_000e2e38;
    iVar4 = DAT_000e2e34;
    if (1 < iVar2) {
      local_40 = 1;
      pAVar8 = key;
      local_34 = key;
      do {
        uVar11 = local_34->rd_key[4];
        local_40 = local_40 + 1;
        local_34 = (AES_KEY *)(local_34->rd_key + 4);
        local_34->rd_key[0] =
             *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + (uVar11 >> 0x18) * 4 + 0x400) * 4 + 0x308) ^
             *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + (uVar11 & 0xff) * 4 + 0x400) * 4 + -0xf8) ^
             *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + ((uVar11 << 8) >> 0x18) * 4 + 0x400) * 4 +
                      0x708) ^
             *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + ((uVar11 << 0x10) >> 0x18) * 4 + 0x400) * 4 +
                      0xb08);
        uVar12 = pAVar8->rd_key[5];
        uVar5 = pAVar8->rd_key[6];
        uVar11 = pAVar8->rd_key[7];
        uVar13 = *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + (uVar12 & 0xff) * 4 + 0x400) * 4 + -0xf8)
        ;
        uVar15 = *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + (uVar12 >> 0x18) * 4 + 0x400) * 4 + 0x308
                          );
        uVar14 = *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + ((uVar12 << 8) >> 0x18) * 4 + 0x400) * 4
                          + 0x708);
        uVar10 = *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + (uVar11 & 0xff) * 4 + 0x400) * 4 + -0xf8)
        ;
        uVar17 = *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + (uVar11 >> 0x18) * 4 + 0x400) * 4 + 0x308
                          );
        uVar16 = *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + ((uVar11 << 8) >> 0x18) * 4 + 0x400) * 4
                          + 0x708);
        uVar7 = *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + ((uVar11 << 0x10) >> 0x18) * 4 + 0x400) *
                                  4 + 0xb08);
        uVar11 = *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + ((uVar12 << 0x10) >> 0x18) * 4 + 0x400) *
                                   4 + 0xb08);
        pAVar8->rd_key[6] =
             *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + (uVar5 >> 0x18) * 4 + 0x400) * 4 + 0x308) ^
             *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + (uVar5 & 0xff) * 4 + 0x400) * 4 + -0xf8) ^
             *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + ((uVar5 << 8) >> 0x18) * 4 + 0x400) * 4 +
                      0x708) ^
             *(uint *)(iVar4 + (uint)*(byte *)(iVar1 + ((uVar5 << 0x10) >> 0x18) * 4 + 0x400) * 4 +
                      0xb08);
        pAVar8->rd_key[7] = uVar10 ^ uVar17 ^ uVar16 ^ uVar7;
        pAVar8->rd_key[5] = uVar13 ^ uVar15 ^ uVar14 ^ uVar11;
        pAVar8 = (AES_KEY *)(pAVar8->rd_key + 4);
      } while (local_40 < key->rounds);
    }
    iVar2 = 0;
  }
  return iVar2;
}

