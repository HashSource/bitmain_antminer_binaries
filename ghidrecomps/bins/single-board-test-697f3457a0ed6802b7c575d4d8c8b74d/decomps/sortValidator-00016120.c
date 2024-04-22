
int sortValidator(void *data,uchar *soln)

{
  uint8_t *puVar1;
  uint32_t uVar2;
  char *pcVar3;
  int extraout_r1;
  int extraout_r1_00;
  int iVar4;
  uint uVar5;
  int iVar6;
  uchar *soln_local;
  void *data_local;
  uint8_t tmpHash [50];
  int i_5;
  uint8_t hash_1 [30];
  uint8_t hash [30];
  uint8_t tmp_data [1344];
  uint32_t real_indices [512];
  uint8_t tmp_hash [30];
  uint8_t vHash [30];
  uint32_t indices [512];
  uint8_t *__tmp_1;
  uint8_t *__tmp;
  int i_1;
  char *hex_buff;
  int solnr;
  int equihashSolutionSize;
  int hashOutput;
  int indicesPerHashOutput;
  uint32_t hashLength;
  int collisionByteLength;
  int collisionBitLength;
  blake2b_state *digest;
  int k;
  int n;
  validData *v;
  uint32_t index_1;
  uint32_t j_4;
  int i_6;
  int j_3;
  int i_4;
  uint32_t level;
  int i_3;
  uint32_t index;
  size_t j_2;
  int i_2;
  uint32_t m;
  int j_1;
  int j;
  int i;
  uint32_t xc_size;
  uint8_t *xc;
  uint8_t *x;
  int err_type;
  uint32_t x_size;
  uint32_t indicesLen;
  
                    /* WARNING: Load size is inaccurate */
  n = *data;
  uVar5 = *(uint *)((int)data + 4);
  digest = *(blake2b_state **)((int)data + 8);
  collisionBitLength = __aeabi_idiv(n,uVar5 + 1);
  iVar4 = collisionBitLength + 0xe;
  if (-1 < collisionBitLength + 7) {
    iVar4 = collisionBitLength + 7;
  }
  hashLength = (iVar4 >> 3) * (uVar5 + 1);
  indicesPerHashOutput = __aeabi_idiv(0x200,n);
  iVar6 = n * indicesPerHashOutput;
  iVar4 = iVar6 + 7;
  if (-1 < iVar6) {
    iVar4 = iVar6;
  }
  hashOutput = iVar4 >> 3;
  iVar4 = __aeabi_idiv(n,uVar5 + 1);
  iVar6 = iVar4 + 1 << (uVar5 & 0xff);
  iVar4 = iVar6 + 7;
  if (-1 < iVar6) {
    iVar4 = iVar6;
  }
  solnr = 0x200;
  indicesLen = 4;
  x_size = 0x200;
  err_type = 0;
  compare_size = 3;
  expandArray(soln,iVar4 >> 3,(uchar *)indices,0x800,collisionBitLength + 1,1);
  memset(vHash,0,0x1e);
  x = (uint8_t *)malloc(0x4400);
  xc = (uint8_t *)malloc(0x4400);
  memset(tmp_hash,0,0x1e);
  i = 0;
  do {
    j = i;
    if (0x1ff < i) {
      for (j_1 = 0; j_1 < solnr; j_1 = j_1 + 1) {
        uVar5 = __bswap_32(indices[j_1]);
        uVar2 = __aeabi_idiv(uVar5,indicesPerHashOutput);
        generateHash(digest,uVar2,tmpHash,hashOutput);
        __aeabi_idivmod(uVar5,indicesPerHashOutput);
        iVar6 = n * extraout_r1;
        iVar4 = iVar6 + 7;
        if (-1 < iVar6) {
          iVar4 = iVar6;
        }
        iVar6 = n + 7;
        if (-1 < n) {
          iVar6 = n;
        }
        expandArray(tmpHash + (iVar4 >> 3),iVar6 >> 3,hash,hashLength,collisionBitLength,0);
        for (m = 0; m < hashLength; m = m + 1) {
          vHash[m] = hash[m] ^ vHash[m];
        }
        memcpy(x + j_1 * (indicesLen + hashLength),hash,hashLength);
        memcpy(x + hashLength + j_1 * (indicesLen + hashLength),indices + j_1,indicesLen);
      }
      iVar4 = isZero(vHash,0x1e);
      if (iVar4 == 0) {
        err_type = 2;
      }
      else {
        memset(vHash,0,0x1e);
        for (i_2 = 0; i_2 < 9; i_2 = i_2 + 1) {
          qsort(x,x_size,hashLength + indicesLen,compareSR + 1);
          xc_size = 0;
          for (j_2 = 0; puVar1 = x, j_2 < x_size; j_2 = j_2 + 2) {
            for (index = 0; index < hashLength; index = index + 1) {
              tmp_hash[index] =
                   x[index + (j_2 + 1) * (indicesLen + hashLength)] ^
                   x[index + j_2 * (indicesLen + hashLength)];
            }
            memcpy(xc + (j_2 >> 1) * (hashLength + indicesLen * 2),tmp_hash,hashLength);
            memcpy(xc + hashLength + (j_2 >> 1) * (hashLength + indicesLen * 2),
                   x + hashLength + j_2 * (indicesLen + hashLength),indicesLen);
            memcpy(xc + indicesLen + (j_2 >> 1) * (hashLength + indicesLen * 2) + hashLength,
                   x + hashLength + (j_2 + 1) * (indicesLen + hashLength),indicesLen);
            xc_size = xc_size + 1;
          }
          indicesLen = indicesLen << 1;
          x = xc;
          xc = puVar1;
          x_size = xc_size;
          compare_size = compare_size + 3;
        }
        for (i_3 = 0; i_3 < 0x200; i_3 = i_3 + 1) {
          uVar5 = __bswap_32(*(uint *)(x + hashLength + i_3 * 4));
          real_indices[i_3] = uVar5;
        }
        for (level = 0; level < 9; level = level + 1) {
          for (i_4 = 0; i_4 < 0x200; i_4 = (2 << (level & 0xff)) + i_4) {
            sort_pair(real_indices + i_4,1 << (level & 0xff));
          }
        }
        indicesLen = 4;
        x_size = 0x200;
        for (j_3 = 0; j_3 < solnr; j_3 = j_3 + 1) {
          i_5 = real_indices[j_3];
          uVar2 = __aeabi_idiv(i_5,indicesPerHashOutput);
          generateHash(digest,uVar2,tmpHash,hashOutput);
          __aeabi_idivmod(i_5,indicesPerHashOutput);
          iVar6 = n * extraout_r1_00;
          iVar4 = iVar6 + 7;
          if (-1 < iVar6) {
            iVar4 = iVar6;
          }
          iVar6 = n + 7;
          if (-1 < n) {
            iVar6 = n;
          }
          expandArray(tmpHash + (iVar4 >> 3),iVar6 >> 3,hash_1,hashLength,collisionBitLength,0);
          i_5 = __bswap_32(real_indices[j_3]);
          memcpy(x + j_3 * (hashLength + 4),hash_1,hashLength);
          memcpy(x + hashLength + j_3 * (hashLength + 4),&i_5,4);
          pcVar3 = bin2hex(x + j_3 * (hashLength + 4),0x22);
          free(pcVar3);
        }
        for (i_6 = 0; i_6 < 9; i_6 = i_6 + 1) {
          xc_size = 0;
          for (j_4 = 0; puVar1 = x, j_4 < x_size; j_4 = j_4 + 2) {
            for (index_1 = 0; index_1 < hashLength; index_1 = index_1 + 1) {
              tmp_hash[index_1] =
                   x[index_1 + (j_4 + 1) * (indicesLen + hashLength)] ^
                   x[index_1 + j_4 * (indicesLen + hashLength)];
            }
            memcpy(xc + (j_4 >> 1) * (hashLength + indicesLen * 2),tmp_hash,hashLength);
            memcpy(xc + hashLength + (j_4 >> 1) * (hashLength + indicesLen * 2),
                   x + hashLength + j_4 * (indicesLen + hashLength),indicesLen);
            memcpy(xc + indicesLen + (j_4 >> 1) * (hashLength + indicesLen * 2) + hashLength,
                   x + hashLength + (j_4 + 1) * (indicesLen + hashLength),indicesLen);
            xc_size = xc_size + 1;
          }
          indicesLen = indicesLen << 1;
          x = xc;
          xc = puVar1;
          x_size = xc_size;
          compare_size = compare_size + 3;
        }
        getIndices(x,hashLength,0x800,0x14,tmp_data,0x540);
        pcVar3 = bin2hex(tmp_data,0x540);
        free(pcVar3);
        pcVar3 = bin2hex(x,indicesLen + hashLength);
        free(pcVar3);
        vHash._0_4_ = *(undefined4 *)x;
        vHash._4_4_ = *(undefined4 *)(x + 4);
        vHash._8_4_ = *(undefined4 *)(x + 8);
        vHash._12_4_ = *(undefined4 *)(x + 0xc);
        vHash._16_4_ = *(undefined4 *)(x + 0x10);
        vHash._20_4_ = *(undefined4 *)(x + 0x14);
        vHash._24_4_ = *(undefined4 *)(x + 0x18);
        vHash._28_2_ = *(undefined2 *)(x + 0x1c);
        iVar4 = isZero(vHash,0x1e);
        if (iVar4 == 0) {
          err_type = 3;
        }
      }
failed:
      free(x);
      free(xc);
      return err_type;
    }
    while (j = j + 1, j < 0x200) {
      if (indices[i] == indices[j]) {
        err_type = 1;
        goto failed;
      }
    }
    i = i + 1;
  } while( true );
}

