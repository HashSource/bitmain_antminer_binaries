
int private_AES_set_encrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
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
  
  if (userKey == (uchar *)0x0 || key == (AES_KEY *)0x0) {
    return -1;
  }
  if ((bits & 0xffffffbfU) == 0x80) {
    iVar3 = 0x80;
    if (bits == 0x80) {
      iVar3 = 10;
    }
    if (bits == 0x80) {
      key->rounds = iVar3;
      goto LAB_000e1eec;
    }
    if (bits == 0xc0) {
      key->rounds = 0xc;
      goto LAB_000e1eec;
    }
  }
  else if (bits != 0x100) {
    return -2;
  }
  key->rounds = 0xe;
LAB_000e1eec:
  uVar13 = ((uint)userKey[1] << 0x10 | (uint)*userKey << 0x18) ^ (uint)userKey[3] |
           (uint)userKey[2] << 8;
  key->rd_key[0] = uVar13;
  uVar7 = ((uint)userKey[5] << 0x10 | (uint)userKey[4] << 0x18) ^ (uint)userKey[7] |
          (uint)userKey[6] << 8;
  key->rd_key[1] = uVar7;
  uVar10 = ((uint)userKey[9] << 0x10 | (uint)userKey[8] << 0x18) ^ (uint)userKey[0xb] |
           (uint)userKey[10] << 8;
  key->rd_key[2] = uVar10;
  bVar1 = userKey[0xc];
  uVar8 = ((uint)userKey[0xd] << 0x10 | (uint)bVar1 << 0x18) ^ (uint)userKey[0xf];
  uVar9 = uVar8 | (uint)userKey[0xe] << 8;
  key->rd_key[3] = uVar9;
  iVar3 = DAT_000e288c;
  if (bits == 0x80) {
    uVar8 = uVar13 ^ 0x1000000 ^ *(uint *)(DAT_000e288c + (uVar8 & 0xff) * 4) & 0xff00 ^
            (uint)*(byte *)(DAT_000e288c + (uint)bVar1 * 4 + 0x400) ^
            *(uint *)(DAT_000e288c + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(DAT_000e288c + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[4] = uVar8;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[5] = uVar7;
    key->rd_key[6] = uVar10;
    uVar13 = *(uint *)(iVar3 + (uVar9 & 0xff) * 4);
    key->rd_key[7] = uVar9;
    uVar8 = uVar8 ^ 0x2000000 ^ uVar13 & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[8] = uVar8;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[9] = uVar7;
    key->rd_key[10] = uVar10;
    uVar13 = *(uint *)(iVar3 + (uVar9 & 0xff) * 4);
    key->rd_key[0xb] = uVar9;
    uVar8 = uVar8 ^ 0x4000000 ^ uVar13 & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[0xc] = uVar8;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[0xd] = uVar7;
    key->rd_key[0xe] = uVar10;
    uVar13 = *(uint *)(iVar3 + (uVar9 & 0xff) * 4);
    key->rd_key[0xf] = uVar9;
    uVar8 = uVar8 ^ 0x8000000 ^ uVar13 & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[0x10] = uVar8;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[0x11] = uVar7;
    key->rd_key[0x12] = uVar10;
    uVar13 = *(uint *)(iVar3 + (uVar9 & 0xff) * 4);
    key->rd_key[0x13] = uVar9;
    uVar8 = uVar8 ^ 0x10000000 ^ uVar13 & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    key->rd_key[0x14] = uVar8;
    uVar10 = uVar10 ^ uVar7;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[0x15] = uVar7;
    key->rd_key[0x16] = uVar10;
    uVar13 = *(uint *)(iVar3 + (uVar9 & 0xff) * 4);
    key->rd_key[0x17] = uVar9;
    uVar8 = uVar8 ^ 0x20000000 ^ uVar13 & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[0x18] = uVar8;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[0x19] = uVar7;
    key->rd_key[0x1a] = uVar10;
    uVar13 = *(uint *)(iVar3 + (uVar9 & 0xff) * 4);
    key->rd_key[0x1b] = uVar9;
    uVar8 = uVar8 ^ 0x40000000 ^ uVar13 & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[0x1c] = uVar8;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[0x1d] = uVar7;
    key->rd_key[0x1e] = uVar10;
    uVar13 = *(uint *)(iVar3 + (uVar9 & 0xff) * 4);
    key->rd_key[0x1f] = uVar9;
    uVar8 = uVar8 + 0x80000000 ^ uVar13 & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[0x20] = uVar8;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[0x21] = uVar7;
    key->rd_key[0x22] = uVar10;
    uVar13 = *(uint *)(iVar3 + (uVar9 & 0xff) * 4);
    key->rd_key[0x23] = uVar9;
    uVar8 = uVar8 ^ 0x1b000000 ^ uVar13 & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    key->rd_key[0x24] = uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[0x25] = uVar7;
    uVar9 = uVar9 ^ uVar10;
    key->rd_key[0x26] = uVar10;
    key->rd_key[0x27] = uVar9;
    uVar8 = uVar8 ^ 0x36000000 ^ *(uint *)(iVar3 + (uVar9 & 0xff) * 4) & 0xff00 ^
            (uint)*(byte *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x400) ^
            *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
            *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
    uVar7 = uVar7 ^ uVar8;
    key->rd_key[0x28] = uVar8;
    uVar10 = uVar10 ^ uVar7;
    key->rd_key[0x29] = uVar7;
    key->rd_key[0x2a] = uVar10;
    key->rd_key[0x2b] = uVar9 ^ uVar10;
  }
  else {
    uVar5 = ((uint)userKey[0x11] << 0x10 | (uint)userKey[0x10] << 0x18) ^ (uint)userKey[0x13] |
            (uint)userKey[0x12] << 8;
    key->rd_key[4] = uVar5;
    bVar1 = userKey[0x14];
    uVar4 = ((uint)userKey[0x15] << 0x10 | (uint)bVar1 << 0x18) ^ (uint)userKey[0x17];
    uVar8 = uVar4 | (uint)userKey[0x16] << 8;
    key->rd_key[5] = uVar8;
    iVar3 = DAT_000e2bd4;
    if (bits == 0xc0) {
      uVar13 = uVar13 ^ 0x1000000 ^ *(uint *)(DAT_000e2bd4 + (uVar4 & 0xff) * 4) & 0xff00 ^
               (uint)*(byte *)(DAT_000e2bd4 + (uint)bVar1 * 4 + 0x400) ^
               *(uint *)(DAT_000e2bd4 + ((uVar8 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
               *(uint *)(DAT_000e2bd4 + ((uVar8 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
      uVar7 = uVar7 ^ uVar13;
      key->rd_key[6] = uVar13;
      uVar10 = uVar10 ^ uVar7;
      key->rd_key[7] = uVar7;
      uVar9 = uVar9 ^ uVar10;
      key->rd_key[8] = uVar10;
      uVar5 = uVar9 ^ uVar5;
      key->rd_key[9] = uVar9;
      uVar8 = uVar8 ^ uVar5;
      key->rd_key[10] = uVar5;
      key->rd_key[0xb] = uVar8;
      uVar13 = uVar13 ^ *(uint *)(iVar3 + (uVar8 & 0xff) * 4) & 0xff00 ^
                        (uint)*(byte *)(iVar3 + (uVar8 >> 0x18) * 4 + 0x400) ^ 0x2000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
      uVar7 = uVar7 ^ uVar13;
      key->rd_key[0xc] = uVar13;
      uVar10 = uVar10 ^ uVar7;
      key->rd_key[0xd] = uVar7;
      uVar9 = uVar9 ^ uVar10;
      key->rd_key[0xe] = uVar10;
      uVar5 = uVar5 ^ uVar9;
      key->rd_key[0xf] = uVar9;
      uVar8 = uVar5 ^ uVar8;
      key->rd_key[0x10] = uVar5;
      key->rd_key[0x11] = uVar8;
      uVar13 = uVar13 ^ *(uint *)(iVar3 + (uVar8 & 0xff) * 4) & 0xff00 ^
                        (uint)*(byte *)(iVar3 + (uVar8 >> 0x18) * 4 + 0x400) ^ 0x4000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
      uVar7 = uVar7 ^ uVar13;
      key->rd_key[0x12] = uVar13;
      uVar10 = uVar10 ^ uVar7;
      key->rd_key[0x13] = uVar7;
      uVar9 = uVar9 ^ uVar10;
      key->rd_key[0x14] = uVar10;
      uVar5 = uVar5 ^ uVar9;
      key->rd_key[0x15] = uVar9;
      uVar8 = uVar8 ^ uVar5;
      key->rd_key[0x16] = uVar5;
      key->rd_key[0x17] = uVar8;
      uVar13 = uVar13 ^ *(uint *)(iVar3 + (uVar8 & 0xff) * 4) & 0xff00 ^
                        (uint)*(byte *)(iVar3 + (uVar8 >> 0x18) * 4 + 0x400) ^ 0x8000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
      uVar7 = uVar7 ^ uVar13;
      key->rd_key[0x18] = uVar13;
      uVar10 = uVar10 ^ uVar7;
      key->rd_key[0x19] = uVar7;
      uVar9 = uVar9 ^ uVar10;
      key->rd_key[0x1a] = uVar10;
      uVar5 = uVar5 ^ uVar9;
      key->rd_key[0x1b] = uVar9;
      uVar8 = uVar8 ^ uVar5;
      key->rd_key[0x1c] = uVar5;
      key->rd_key[0x1d] = uVar8;
      uVar13 = uVar13 ^ *(uint *)(iVar3 + (uVar8 & 0xff) * 4) & 0xff00 ^
                        (uint)*(byte *)(iVar3 + (uVar8 >> 0x18) * 4 + 0x400) ^ 0x10000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
      uVar7 = uVar7 ^ uVar13;
      key->rd_key[0x1e] = uVar13;
      uVar10 = uVar10 ^ uVar7;
      key->rd_key[0x1f] = uVar7;
      uVar9 = uVar9 ^ uVar10;
      key->rd_key[0x20] = uVar10;
      uVar5 = uVar5 ^ uVar9;
      key->rd_key[0x21] = uVar9;
      uVar8 = uVar8 ^ uVar5;
      key->rd_key[0x22] = uVar5;
      key->rd_key[0x23] = uVar8;
      uVar13 = uVar13 ^ *(uint *)(iVar3 + (uVar8 & 0xff) * 4) & 0xff00 ^
                        (uint)*(byte *)(iVar3 + (uVar8 >> 0x18) * 4 + 0x400) ^ 0x20000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
      uVar7 = uVar7 ^ uVar13;
      key->rd_key[0x24] = uVar13;
      uVar10 = uVar10 ^ uVar7;
      key->rd_key[0x25] = uVar7;
      uVar9 = uVar9 ^ uVar10;
      key->rd_key[0x26] = uVar10;
      uVar5 = uVar5 ^ uVar9;
      key->rd_key[0x27] = uVar9;
      uVar8 = uVar8 ^ uVar5;
      key->rd_key[0x28] = uVar5;
      key->rd_key[0x29] = uVar8;
      uVar13 = uVar13 ^ *(uint *)(iVar3 + (uVar8 & 0xff) * 4) & 0xff00 ^
                        (uint)*(byte *)(iVar3 + (uVar8 >> 0x18) * 4 + 0x400) ^ 0x40000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
      uVar7 = uVar7 ^ uVar13;
      key->rd_key[0x2a] = uVar13;
      uVar10 = uVar10 ^ uVar7;
      key->rd_key[0x2b] = uVar7;
      uVar9 = uVar9 ^ uVar10;
      key->rd_key[0x2c] = uVar10;
      key->rd_key[0x2d] = uVar9;
      uVar8 = uVar8 ^ uVar5 ^ uVar9;
      key->rd_key[0x2e] = uVar5 ^ uVar9;
      key->rd_key[0x2f] = uVar8;
      uVar13 = uVar13 ^ *(uint *)(iVar3 + ((uVar8 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                        (*(uint *)(iVar3 + (uVar8 & 0xff) * 4) & 0xff00 ^
                        (uint)*(byte *)(iVar3 + (uVar8 >> 0x18) * 4 + 0x400)) + 0x80000000 ^
                        *(uint *)(iVar3 + ((uVar8 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
      uVar7 = uVar7 ^ uVar13;
      key->rd_key[0x30] = uVar13;
      uVar10 = uVar10 ^ uVar7;
      key->rd_key[0x31] = uVar7;
      key->rd_key[0x32] = uVar10;
      key->rd_key[0x33] = uVar9 ^ uVar10;
    }
    else {
      uVar6 = ((uint)userKey[0x19] << 0x10 | (uint)userKey[0x18] << 0x18) ^ (uint)userKey[0x1b] |
              (uint)userKey[0x1a] << 8;
      key->rd_key[6] = uVar6;
      bVar1 = userKey[0x1c];
      uVar2 = ((uint)userKey[0x1d] << 0x10 | (uint)bVar1 << 0x18) ^ (uint)userKey[0x1f];
      uVar4 = uVar2 | (uint)userKey[0x1e] << 8;
      key->rd_key[7] = uVar4;
      iVar3 = DAT_000e2390;
      if (bits == 0x100) {
        uVar2 = uVar13 ^ 0x1000000 ^ *(uint *)(DAT_000e2390 + (uVar2 & 0xff) * 4) & 0xff00 ^
                (uint)*(byte *)(DAT_000e2390 + (uint)bVar1 * 4 + 0x400) ^
                *(uint *)(DAT_000e2390 + ((uVar4 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                *(uint *)(DAT_000e2390 + ((uVar4 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
        uVar7 = uVar7 ^ uVar2;
        key->rd_key[8] = uVar2;
        uVar10 = uVar10 ^ uVar7;
        key->rd_key[9] = uVar7;
        uVar9 = uVar9 ^ uVar10;
        key->rd_key[10] = uVar10;
        key->rd_key[0xb] = uVar9;
        uVar13 = *(uint *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x800) & 0xff000000 ^
                 (uint)*(byte *)(iVar3 + (uVar9 & 0xff) * 4 + 0x400) ^ uVar5 ^
                 *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0xc00) & 0xff0000 ^
                 *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4) & 0xff00;
        uVar8 = uVar8 ^ uVar13;
        key->rd_key[0xc] = uVar13;
        uVar6 = uVar6 ^ uVar8;
        uVar4 = uVar4 ^ uVar6;
        key->rd_key[0xd] = uVar8;
        uVar12 = *(uint *)(iVar3 + (uVar4 & 0xff) * 4);
        bVar1 = *(byte *)(iVar3 + (uVar4 >> 0x18) * 4 + 0x400);
        uVar11 = *(uint *)(iVar3 + ((uVar4 << 8) >> 0x18) * 4 + 0x800);
        key->rd_key[0xe] = uVar6;
        uVar5 = *(uint *)(iVar3 + ((uVar4 << 0x10) >> 0x18) * 4 + 0xc00);
        key->rd_key[0xf] = uVar4;
        uVar2 = uVar2 ^ uVar12 & 0xff00 ^ (uint)bVar1 ^ 0x2000000 ^ uVar11 & 0xff000000 ^
                        uVar5 & 0xff0000;
        uVar7 = uVar7 ^ uVar2;
        key->rd_key[0x10] = uVar2;
        key->rd_key[0x11] = uVar7;
        uVar10 = uVar10 ^ uVar7;
        uVar9 = uVar9 ^ uVar10;
        key->rd_key[0x12] = uVar10;
        key->rd_key[0x13] = uVar9;
        uVar13 = *(uint *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x800) & 0xff000000 ^
                 (uint)*(byte *)(iVar3 + (uVar9 & 0xff) * 4 + 0x400) ^ uVar13 ^
                 *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0xc00) & 0xff0000 ^
                 *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4) & 0xff00;
        uVar8 = uVar8 ^ uVar13;
        key->rd_key[0x14] = uVar13;
        uVar6 = uVar6 ^ uVar8;
        uVar4 = uVar4 ^ uVar6;
        key->rd_key[0x15] = uVar8;
        uVar12 = *(uint *)(iVar3 + (uVar4 & 0xff) * 4);
        bVar1 = *(byte *)(iVar3 + (uVar4 >> 0x18) * 4 + 0x400);
        uVar11 = *(uint *)(iVar3 + ((uVar4 << 8) >> 0x18) * 4 + 0x800);
        key->rd_key[0x16] = uVar6;
        uVar5 = *(uint *)(iVar3 + ((uVar4 << 0x10) >> 0x18) * 4 + 0xc00);
        key->rd_key[0x17] = uVar4;
        uVar2 = uVar2 ^ uVar12 & 0xff00 ^ (uint)bVar1 ^ 0x4000000 ^ uVar11 & 0xff000000 ^
                        uVar5 & 0xff0000;
        uVar7 = uVar7 ^ uVar2;
        key->rd_key[0x18] = uVar2;
        uVar10 = uVar10 ^ uVar7;
        key->rd_key[0x19] = uVar7;
        uVar9 = uVar9 ^ uVar10;
        key->rd_key[0x1a] = uVar10;
        uVar5 = *(uint *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x800);
        bVar1 = *(byte *)(iVar3 + (uVar9 & 0xff) * 4 + 0x400);
        key->rd_key[0x1b] = uVar9;
        uVar13 = uVar5 & 0xff000000 ^ (uint)bVar1 ^ uVar13 ^
                 *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0xc00) & 0xff0000 ^
                 *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4) & 0xff00;
        uVar8 = uVar8 ^ uVar13;
        key->rd_key[0x1c] = uVar13;
        uVar6 = uVar6 ^ uVar8;
        uVar4 = uVar4 ^ uVar6;
        key->rd_key[0x1d] = uVar8;
        key->rd_key[0x1e] = uVar6;
        uVar11 = *(uint *)(iVar3 + (uVar4 & 0xff) * 4);
        bVar1 = *(byte *)(iVar3 + (uVar4 >> 0x18) * 4 + 0x400);
        uVar5 = *(uint *)(iVar3 + ((uVar4 << 8) >> 0x18) * 4 + 0x800);
        key->rd_key[0x1f] = uVar4;
        uVar2 = uVar2 ^ uVar11 & 0xff00 ^ (uint)bVar1 ^ 0x8000000 ^ uVar5 & 0xff000000 ^
                        *(uint *)(iVar3 + ((uVar4 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000;
        key->rd_key[0x20] = uVar2;
        uVar7 = uVar7 ^ uVar2;
        key->rd_key[0x21] = uVar7;
        uVar10 = uVar10 ^ uVar7;
        uVar9 = uVar9 ^ uVar10;
        key->rd_key[0x22] = uVar10;
        uVar5 = *(uint *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x800);
        bVar1 = *(byte *)(iVar3 + (uVar9 & 0xff) * 4 + 0x400);
        key->rd_key[0x23] = uVar9;
        uVar13 = uVar5 & 0xff000000 ^ (uint)bVar1 ^ uVar13 ^
                 *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0xc00) & 0xff0000 ^
                 *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4) & 0xff00;
        uVar8 = uVar8 ^ uVar13;
        key->rd_key[0x24] = uVar13;
        uVar6 = uVar6 ^ uVar8;
        uVar4 = uVar4 ^ uVar6;
        key->rd_key[0x25] = uVar8;
        uVar12 = *(uint *)(iVar3 + (uVar4 & 0xff) * 4);
        bVar1 = *(byte *)(iVar3 + (uVar4 >> 0x18) * 4 + 0x400);
        uVar11 = *(uint *)(iVar3 + ((uVar4 << 8) >> 0x18) * 4 + 0x800);
        key->rd_key[0x26] = uVar6;
        uVar5 = *(uint *)(iVar3 + ((uVar4 << 0x10) >> 0x18) * 4 + 0xc00);
        key->rd_key[0x27] = uVar4;
        uVar2 = uVar2 ^ uVar12 & 0xff00 ^ (uint)bVar1 ^ 0x10000000 ^ uVar11 & 0xff000000 ^
                        uVar5 & 0xff0000;
        uVar7 = uVar7 ^ uVar2;
        key->rd_key[0x28] = uVar2;
        uVar10 = uVar10 ^ uVar7;
        key->rd_key[0x29] = uVar7;
        uVar9 = uVar9 ^ uVar10;
        key->rd_key[0x2a] = uVar10;
        key->rd_key[0x2b] = uVar9;
        uVar11 = *(uint *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x800) & 0xff000000 ^
                 (uint)*(byte *)(iVar3 + (uVar9 & 0xff) * 4 + 0x400) ^ uVar13 ^
                 *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0xc00) & 0xff0000 ^
                 *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4) & 0xff00;
        key->rd_key[0x2c] = uVar11;
        uVar8 = uVar11 ^ uVar8;
        uVar6 = uVar6 ^ uVar8;
        uVar4 = uVar4 ^ uVar6;
        key->rd_key[0x2d] = uVar8;
        key->rd_key[0x2e] = uVar6;
        uVar12 = *(uint *)(iVar3 + (uVar4 & 0xff) * 4);
        bVar1 = *(byte *)(iVar3 + (uVar4 >> 0x18) * 4 + 0x400);
        uVar5 = *(uint *)(iVar3 + ((uVar4 << 8) >> 0x18) * 4 + 0x800);
        uVar13 = *(uint *)(iVar3 + ((uVar4 << 0x10) >> 0x18) * 4 + 0xc00);
        key->rd_key[0x2f] = uVar4;
        uVar2 = uVar2 ^ uVar12 & 0xff00 ^ (uint)bVar1 ^ 0x20000000 ^ uVar5 & 0xff000000 ^
                        uVar13 & 0xff0000;
        uVar7 = uVar7 ^ uVar2;
        key->rd_key[0x30] = uVar2;
        uVar10 = uVar10 ^ uVar7;
        uVar9 = uVar9 ^ uVar10;
        key->rd_key[0x31] = uVar7;
        key->rd_key[0x32] = uVar10;
        key->rd_key[0x33] = uVar9;
        uVar13 = *(uint *)(iVar3 + (uVar9 >> 0x18) * 4 + 0x800) & 0xff000000 ^
                 (uint)*(byte *)(iVar3 + (uVar9 & 0xff) * 4 + 0x400) ^ uVar11 ^
                 *(uint *)(iVar3 + ((uVar9 << 8) >> 0x18) * 4 + 0xc00) & 0xff0000 ^
                 *(uint *)(iVar3 + ((uVar9 << 0x10) >> 0x18) * 4) & 0xff00;
        uVar8 = uVar13 ^ uVar8;
        key->rd_key[0x34] = uVar13;
        key->rd_key[0x35] = uVar8;
        uVar8 = uVar8 ^ uVar6;
        uVar4 = uVar8 ^ uVar4;
        key->rd_key[0x36] = uVar8;
        key->rd_key[0x37] = uVar4;
        uVar2 = *(uint *)(iVar3 + (uVar4 & 0xff) * 4) & 0xff00 ^
                (uint)*(byte *)(iVar3 + (uVar4 >> 0x18) * 4 + 0x400) ^ 0x40000000 ^
                *(uint *)(iVar3 + ((uVar4 << 8) >> 0x18) * 4 + 0x800) & 0xff000000 ^
                *(uint *)(iVar3 + ((uVar4 << 0x10) >> 0x18) * 4 + 0xc00) & 0xff0000 ^ uVar2;
        uVar7 = uVar7 ^ uVar2;
        key->rd_key[0x38] = uVar2;
        uVar10 = uVar10 ^ uVar7;
        key->rd_key[0x39] = uVar7;
        key->rd_key[0x3a] = uVar10;
        key->rd_key[0x3b] = uVar9 ^ uVar10;
      }
    }
  }
  return 0;
}

