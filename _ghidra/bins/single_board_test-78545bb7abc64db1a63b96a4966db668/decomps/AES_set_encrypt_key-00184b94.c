
int AES_set_encrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  AES_KEY *pAVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  
  if (key == (AES_KEY *)0x0 || userKey == (uchar *)0x0) {
    return -1;
  }
  if ((bits & 0xffffffbfU) == 0x80) {
    iVar4 = 0x80;
    if (bits == 0x80) {
      iVar4 = 10;
    }
    if (bits == 0x80) {
      key->rounds = iVar4;
      goto LAB_00184bc0;
    }
    if (bits == 0xc0) {
      key->rounds = 0xc;
      goto LAB_00184bc0;
    }
  }
  else if (bits != 0x100) {
    return -2;
  }
  key->rounds = 0xe;
LAB_00184bc0:
  uVar6 = ((uint)userKey[1] << 0x10 | (uint)*userKey << 0x18) ^ (uint)userKey[3] |
          (uint)userKey[2] << 8;
  key->rd_key[0] = uVar6;
  uVar11 = ((uint)userKey[5] << 0x10 | (uint)userKey[4] << 0x18) ^ (uint)userKey[7] |
           (uint)userKey[6] << 8;
  key->rd_key[1] = uVar11;
  uVar8 = ((uint)userKey[9] << 0x10 | (uint)userKey[8] << 0x18) ^ (uint)userKey[0xb] |
          (uint)userKey[10] << 8;
  key->rd_key[2] = uVar8;
  bVar1 = userKey[0xc];
  uVar2 = (uint)userKey[0xf] ^ ((uint)userKey[0xd] << 0x10 | (uint)bVar1 << 0x18);
  uVar3 = uVar2 | (uint)userKey[0xe] << 8;
  key->rd_key[3] = uVar3;
  if (bits == 0x80) {
    uVar2 = *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000 ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
            (uint)(byte)Te1[(uint)bVar1 * 4] ^
            *(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x1000000;
    uVar11 = uVar2 ^ uVar11;
    uVar8 = uVar11 ^ uVar8;
    key->rd_key[4] = uVar2;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[5] = uVar11;
    key->rd_key[6] = uVar8;
    uVar6 = *(uint *)(&Te0 + (uVar3 & 0xff) * 4);
    key->rd_key[7] = uVar3;
    uVar2 = uVar6 & 0xff00 ^ uVar2 ^ 0x2000000 ^ (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
            *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
    uVar11 = uVar11 ^ uVar2;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[8] = uVar2;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[9] = uVar11;
    key->rd_key[10] = uVar8;
    uVar6 = *(uint *)(&Te0 + (uVar3 & 0xff) * 4);
    key->rd_key[0xb] = uVar3;
    uVar2 = uVar6 & 0xff00 ^ uVar2 ^ 0x4000000 ^ (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
            *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
    uVar11 = uVar11 ^ uVar2;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[0xc] = uVar2;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[0xd] = uVar11;
    key->rd_key[0xe] = uVar8;
    uVar6 = *(uint *)(&Te0 + (uVar3 & 0xff) * 4);
    key->rd_key[0xf] = uVar3;
    uVar2 = *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000 ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
            uVar6 & 0xff00 ^ uVar2 ^ 0x8000000 ^ (uint)(byte)Te1[(uVar3 >> 0x18) * 4];
    uVar11 = uVar11 ^ uVar2;
    key->rd_key[0x10] = uVar2;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[0x11] = uVar11;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[0x12] = uVar8;
    key->rd_key[0x13] = uVar3;
    uVar2 = *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000 ^
            *(uint *)(&Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar2 ^ 0x10000000 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000;
    uVar11 = uVar11 ^ uVar2;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[0x14] = uVar2;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[0x15] = uVar11;
    key->rd_key[0x16] = uVar8;
    uVar6 = *(uint *)(&Te0 + (uVar3 & 0xff) * 4);
    key->rd_key[0x17] = uVar3;
    uVar2 = *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000 ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
            uVar6 & 0xff00 ^ uVar2 ^ 0x20000000 ^ (uint)(byte)Te1[(uVar3 >> 0x18) * 4];
    uVar11 = uVar11 ^ uVar2;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[0x18] = uVar2;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[0x19] = uVar11;
    key->rd_key[0x1a] = uVar8;
    uVar6 = *(uint *)(&Te0 + (uVar3 & 0xff) * 4);
    key->rd_key[0x1b] = uVar3;
    uVar2 = *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000 ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
            uVar6 & 0xff00 ^ uVar2 ^ 0x40000000 ^ (uint)(byte)Te1[(uVar3 >> 0x18) * 4];
    uVar11 = uVar11 ^ uVar2;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[0x1c] = uVar2;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[0x1d] = uVar11;
    key->rd_key[0x1e] = uVar8;
    uVar6 = *(uint *)(&Te0 + (uVar3 & 0xff) * 4);
    key->rd_key[0x1f] = uVar3;
    uVar2 = *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000 ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
            uVar6 & 0xff00 ^ uVar2 + 0x80000000 ^ (uint)(byte)Te1[(uVar3 >> 0x18) * 4];
    uVar11 = uVar11 ^ uVar2;
    key->rd_key[0x20] = uVar2;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[0x21] = uVar11;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[0x22] = uVar8;
    key->rd_key[0x23] = uVar3;
    uVar6 = *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000 ^
            *(uint *)(&Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar2 ^ 0x1b000000 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000;
    uVar11 = uVar11 ^ uVar6;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[0x24] = uVar6;
    uVar3 = uVar3 ^ uVar8;
    key->rd_key[0x25] = uVar11;
    key->rd_key[0x26] = uVar8;
    uVar7 = *(uint *)(&Te0 + (uVar3 & 0xff) * 4);
    bVar1 = Te1[(uVar3 >> 0x18) * 4];
    uVar10 = *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4);
    uVar2 = *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4);
    key->rd_key[0x27] = uVar3;
    uVar2 = uVar2 & 0xff0000 ^
            uVar10 & 0xff000000 ^ uVar6 ^ 0x36000000 ^ uVar7 & 0xff00 ^ (uint)bVar1;
    uVar11 = uVar11 ^ uVar2;
    key->rd_key[0x28] = uVar2;
    uVar8 = uVar8 ^ uVar11;
    key->rd_key[0x29] = uVar11;
    key->rd_key[0x2a] = uVar8;
    key->rd_key[0x2b] = uVar3 ^ uVar8;
  }
  else {
    uVar10 = ((uint)userKey[0x11] << 0x10 | (uint)userKey[0x10] << 0x18) ^ (uint)userKey[0x13] |
             (uint)userKey[0x12] << 8;
    key->rd_key[4] = uVar10;
    bVar1 = userKey[0x14];
    uVar7 = ((uint)userKey[0x15] << 0x10 | (uint)bVar1 << 0x18) ^ (uint)userKey[0x17];
    uVar2 = uVar7 | (uint)userKey[0x16] << 8;
    key->rd_key[5] = uVar2;
    if (bits == 0xc0) {
      uVar6 = *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^
              *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
              *(uint *)(&Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x1000000 ^
              (uint)(byte)Te1[(uint)bVar1 * 4];
      uVar11 = uVar11 ^ uVar6;
      key->rd_key[6] = uVar6;
      uVar8 = uVar8 ^ uVar11;
      key->rd_key[7] = uVar11;
      uVar3 = uVar3 ^ uVar8;
      key->rd_key[8] = uVar8;
      uVar10 = uVar3 ^ uVar10;
      key->rd_key[9] = uVar3;
      uVar2 = uVar2 ^ uVar10;
      key->rd_key[10] = uVar10;
      key->rd_key[0xb] = uVar2;
      uVar6 = *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
              *(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
              0x2000000 ^ *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
      uVar11 = uVar11 ^ uVar6;
      key->rd_key[0xc] = uVar6;
      uVar8 = uVar8 ^ uVar11;
      key->rd_key[0xd] = uVar11;
      uVar3 = uVar3 ^ uVar8;
      key->rd_key[0xe] = uVar8;
      uVar10 = uVar10 ^ uVar3;
      key->rd_key[0xf] = uVar3;
      uVar2 = uVar2 ^ uVar10;
      key->rd_key[0x10] = uVar10;
      key->rd_key[0x11] = uVar2;
      uVar6 = *(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
              0x4000000 ^ *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
              *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
      uVar11 = uVar11 ^ uVar6;
      key->rd_key[0x12] = uVar6;
      uVar8 = uVar8 ^ uVar11;
      key->rd_key[0x13] = uVar11;
      uVar3 = uVar3 ^ uVar8;
      key->rd_key[0x14] = uVar8;
      uVar10 = uVar10 ^ uVar3;
      key->rd_key[0x15] = uVar3;
      uVar2 = uVar2 ^ uVar10;
      key->rd_key[0x16] = uVar10;
      key->rd_key[0x17] = uVar2;
      uVar6 = *(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
              0x8000000 ^ *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
              *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
      uVar11 = uVar11 ^ uVar6;
      key->rd_key[0x18] = uVar6;
      uVar8 = uVar8 ^ uVar11;
      key->rd_key[0x19] = uVar11;
      uVar3 = uVar3 ^ uVar8;
      key->rd_key[0x1a] = uVar8;
      uVar10 = uVar10 ^ uVar3;
      key->rd_key[0x1b] = uVar3;
      uVar2 = uVar2 ^ uVar10;
      key->rd_key[0x1c] = uVar10;
      key->rd_key[0x1d] = uVar2;
      uVar6 = *(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
              0x10000000 ^ *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
              *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
      uVar11 = uVar11 ^ uVar6;
      key->rd_key[0x1e] = uVar6;
      uVar8 = uVar8 ^ uVar11;
      key->rd_key[0x1f] = uVar11;
      uVar3 = uVar3 ^ uVar8;
      key->rd_key[0x20] = uVar8;
      uVar10 = uVar10 ^ uVar3;
      key->rd_key[0x21] = uVar3;
      uVar2 = uVar2 ^ uVar10;
      key->rd_key[0x22] = uVar10;
      key->rd_key[0x23] = uVar2;
      uVar6 = *(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
              0x20000000 ^ *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
              *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
      uVar11 = uVar11 ^ uVar6;
      key->rd_key[0x24] = uVar6;
      uVar8 = uVar8 ^ uVar11;
      key->rd_key[0x25] = uVar11;
      uVar3 = uVar3 ^ uVar8;
      key->rd_key[0x26] = uVar8;
      uVar10 = uVar10 ^ uVar3;
      key->rd_key[0x27] = uVar3;
      uVar2 = uVar2 ^ uVar10;
      key->rd_key[0x28] = uVar10;
      key->rd_key[0x29] = uVar2;
      uVar6 = *(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
              0x40000000 ^ *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
              *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
      uVar11 = uVar11 ^ uVar6;
      key->rd_key[0x2a] = uVar6;
      uVar8 = uVar8 ^ uVar11;
      key->rd_key[0x2b] = uVar11;
      uVar3 = uVar3 ^ uVar8;
      key->rd_key[0x2c] = uVar8;
      key->rd_key[0x2d] = uVar3;
      uVar2 = uVar2 ^ uVar10 ^ uVar3;
      key->rd_key[0x2e] = uVar10 ^ uVar3;
      key->rd_key[0x2f] = uVar2;
      uVar6 = uVar6 ^ *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^
                      *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
                      (*(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^
                      (uint)(byte)Te1[(uVar2 >> 0x18) * 4]) + 0x80000000;
      uVar11 = uVar6 ^ uVar11;
      key->rd_key[0x30] = uVar6;
      uVar8 = uVar11 ^ uVar8;
      key->rd_key[0x31] = uVar11;
      key->rd_key[0x32] = uVar8;
      key->rd_key[0x33] = uVar3 ^ uVar8;
    }
    else {
      key->rd_key[6] =
           ((uint)userKey[0x19] << 0x10 | (uint)userKey[0x18] << 0x18) ^ (uint)userKey[0x1b] |
           (uint)userKey[0x1a] << 8;
      key->rd_key[7] =
           ((uint)userKey[0x1d] << 0x10 | (uint)userKey[0x1c] << 0x18) ^ (uint)userKey[0x1f] |
           (uint)userKey[0x1e] << 8;
      if (bits == 0x100) {
        pAVar5 = key;
        puVar9 = (uint *)rcon;
        while( true ) {
          uVar2 = pAVar5->rd_key[7];
          uVar6 = *(uint *)(Te3 + ((uVar2 << 0x10) >> 0x18) * 4) & 0xff0000 ^
                  *(uint *)(Te2 + ((uVar2 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(&Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ *puVar9 ^ uVar6 ^
                  (uint)(byte)Te1[(uVar2 >> 0x18) * 4];
          uVar11 = uVar11 ^ uVar6;
          pAVar5->rd_key[8] = uVar6;
          uVar8 = uVar8 ^ uVar11;
          pAVar5->rd_key[9] = uVar11;
          uVar3 = uVar3 ^ uVar8;
          pAVar5->rd_key[10] = uVar8;
          pAVar5->rd_key[0xb] = uVar3;
          if (pAVar5 == (AES_KEY *)(key->rd_key + 0x30)) break;
          uVar10 = *(uint *)(Te2 + (uVar3 >> 0x18) * 4) & 0xff000000 ^
                   (uint)(byte)Te1[(uVar3 & 0xff) * 4] ^ pAVar5->rd_key[4] ^
                   *(uint *)(Te3 + ((uVar3 << 8) >> 0x18) * 4) & 0xff0000 ^
                   *(uint *)(&Te0 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff00;
          uVar7 = pAVar5->rd_key[5] ^ uVar10;
          pAVar5->rd_key[0xc] = uVar10;
          pAVar5->rd_key[0xd] = uVar7;
          uVar7 = pAVar5->rd_key[6] ^ uVar7;
          pAVar5->rd_key[0xe] = uVar7;
          pAVar5->rd_key[0xf] = uVar2 ^ uVar7;
          pAVar5 = (AES_KEY *)(pAVar5->rd_key + 8);
          puVar9 = puVar9 + 1;
        }
      }
    }
  }
  return 0;
}

