
int sortValidator(void *data,uchar *soln)

{
  uint8_t *puVar1;
  size_t bit_len;
  int iVar2;
  uint32_t uVar3;
  char *pcVar4;
  int extraout_r1;
  int extraout_r1_00;
  int iVar5;
  int iVar6;
  uint uVar7;
  blake2b_state *S;
  size_t out_len;
  int iVar8;
  int iVar9;
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
  iVar6 = *data;
  uVar7 = *(uint *)((int)data + 4);
  S = *(blake2b_state **)((int)data + 8);
  bit_len = __aeabi_idiv(iVar6,uVar7 + 1);
  iVar5 = bit_len + 0xe;
  if (-1 < (int)(bit_len + 7)) {
    iVar5 = bit_len + 7;
  }
  out_len = (iVar5 >> 3) * (uVar7 + 1);
  iVar2 = __aeabi_idiv(0x200,iVar6);
  iVar8 = iVar6 * iVar2;
  iVar5 = iVar8 + 7;
  if (-1 < iVar8) {
    iVar5 = iVar8;
  }
  iVar8 = __aeabi_idiv(iVar6,uVar7 + 1);
  iVar9 = iVar8 + 1 << (uVar7 & 0xff);
  iVar8 = iVar9 + 7;
  if (-1 < iVar9) {
    iVar8 = iVar9;
  }
  indicesLen = 4;
  x_size = 0x200;
  err_type = 0;
  compare_size = 3;
  expandArray(soln,iVar8 >> 3,(uchar *)indices,0x800,bit_len + 1,1);
  memset(vHash,0,0x1e);
  x = (uint8_t *)malloc(0x4400);
  xc = (uint8_t *)malloc(0x4400);
  memset(tmp_hash,0,0x1e);
  i = 0;
  do {
    j = i;
    if (0x1ff < i) {
      for (j_1 = 0; j_1 < 0x200; j_1 = j_1 + 1) {
        uVar7 = __bswap_32(indices[j_1]);
        uVar3 = __aeabi_idiv(uVar7,iVar2);
        generateHash(S,uVar3,tmpHash,iVar5 >> 3);
        __aeabi_idivmod(uVar7,iVar2);
        iVar9 = iVar6 * extraout_r1;
        iVar8 = iVar9 + 7;
        if (-1 < iVar9) {
          iVar8 = iVar9;
        }
        iVar9 = iVar6 + 7;
        if (-1 < iVar6) {
          iVar9 = iVar6;
        }
        expandArray(tmpHash + (iVar8 >> 3),iVar9 >> 3,hash,out_len,bit_len,0);
        for (m = 0; m < out_len; m = m + 1) {
          vHash[m] = hash[m] ^ vHash[m];
        }
        memcpy(x + j_1 * (out_len + 4),hash,out_len);
        memcpy(x + out_len + j_1 * (out_len + 4),indices + j_1,4);
      }
      iVar8 = isZero(vHash,0x1e);
      if (iVar8 == 0) {
        err_type = 2;
      }
      else {
        memset(vHash,0,0x1e);
        for (i_2 = 0; puVar1 = x, i_2 < 9; i_2 = i_2 + 1) {
          qsort(x,x_size,out_len + indicesLen,(__compar_fn_t)0x16055);
          xc_size = 0;
          for (j_2 = 0; j_2 < x_size; j_2 = j_2 + 2) {
            for (index = 0; index < out_len; index = index + 1) {
              tmp_hash[index] =
                   x[index + (j_2 + 1) * (indicesLen + out_len)] ^
                   x[index + j_2 * (indicesLen + out_len)];
            }
            memcpy(xc + (j_2 >> 1) * (out_len + indicesLen * 2),tmp_hash,out_len);
            memcpy(xc + out_len + (j_2 >> 1) * (out_len + indicesLen * 2),
                   x + out_len + j_2 * (indicesLen + out_len),indicesLen);
            memcpy(xc + indicesLen + (j_2 >> 1) * (out_len + indicesLen * 2) + out_len,
                   x + out_len + (j_2 + 1) * (indicesLen + out_len),indicesLen);
            xc_size = xc_size + 1;
          }
          indicesLen = indicesLen << 1;
          x = xc;
          xc = puVar1;
          x_size = xc_size;
          compare_size = compare_size + 3;
        }
        for (i_3 = 0; i_3 < 0x200; i_3 = i_3 + 1) {
          uVar7 = __bswap_32(*(uint *)(x + out_len + i_3 * 4));
          real_indices[i_3] = uVar7;
        }
        for (level = 0; level < 9; level = level + 1) {
          for (i_4 = 0; i_4 < 0x200; i_4 = (2 << (level & 0xff)) + i_4) {
            sort_pair(real_indices + i_4,1 << (level & 0xff));
          }
        }
        indicesLen = 4;
        x_size = 0x200;
        for (j_3 = 0; j_3 < 0x200; j_3 = j_3 + 1) {
          i_5 = real_indices[j_3];
          uVar3 = __aeabi_idiv(i_5,iVar2);
          generateHash(S,uVar3,tmpHash,iVar5 >> 3);
          __aeabi_idivmod(i_5,iVar2);
          iVar9 = iVar6 * extraout_r1_00;
          iVar8 = iVar9 + 7;
          if (-1 < iVar9) {
            iVar8 = iVar9;
          }
          iVar9 = iVar6 + 7;
          if (-1 < iVar6) {
            iVar9 = iVar6;
          }
          expandArray(tmpHash + (iVar8 >> 3),iVar9 >> 3,hash_1,out_len,bit_len,0);
          i_5 = __bswap_32(real_indices[j_3]);
          memcpy(x + j_3 * (out_len + 4),hash_1,out_len);
          memcpy(x + out_len + j_3 * (out_len + 4),&i_5,4);
          pcVar4 = bin2hex(x + j_3 * (out_len + 4),0x22);
          free(pcVar4);
        }
        for (i_6 = 0; puVar1 = x, i_6 < 9; i_6 = i_6 + 1) {
          xc_size = 0;
          for (j_4 = 0; j_4 < x_size; j_4 = j_4 + 2) {
            for (index_1 = 0; index_1 < out_len; index_1 = index_1 + 1) {
              tmp_hash[index_1] =
                   x[index_1 + (j_4 + 1) * (indicesLen + out_len)] ^
                   x[index_1 + j_4 * (indicesLen + out_len)];
            }
            memcpy(xc + (j_4 >> 1) * (out_len + indicesLen * 2),tmp_hash,out_len);
            memcpy(xc + out_len + (j_4 >> 1) * (out_len + indicesLen * 2),
                   x + out_len + j_4 * (indicesLen + out_len),indicesLen);
            memcpy(xc + indicesLen + (j_4 >> 1) * (out_len + indicesLen * 2) + out_len,
                   x + out_len + (j_4 + 1) * (indicesLen + out_len),indicesLen);
            xc_size = xc_size + 1;
          }
          indicesLen = indicesLen << 1;
          x = xc;
          xc = puVar1;
          x_size = xc_size;
          compare_size = compare_size + 3;
        }
        getIndices(x,out_len,0x800,0x14,tmp_data,0x540);
        pcVar4 = bin2hex(tmp_data,0x540);
        free(pcVar4);
        pcVar4 = bin2hex(x,indicesLen + out_len);
        free(pcVar4);
        vHash._0_4_ = *(undefined4 *)x;
        vHash._4_4_ = *(undefined4 *)(x + 4);
        vHash._8_4_ = *(undefined4 *)(x + 8);
        vHash._12_4_ = *(undefined4 *)(x + 0xc);
        vHash._16_4_ = *(undefined4 *)(x + 0x10);
        vHash._20_4_ = *(undefined4 *)(x + 0x14);
        vHash._24_4_ = *(undefined4 *)(x + 0x18);
        vHash._28_2_ = *(undefined2 *)(x + 0x1c);
        iVar5 = isZero(vHash,0x1e);
        if (iVar5 == 0) {
          err_type = 3;
        }
      }
LAB_000170c6:
      free(x);
      free(xc);
      return err_type;
    }
    while (j = j + 1, j < 0x200) {
      if (indices[i] == indices[j]) {
        err_type = 1;
        goto LAB_000170c6;
      }
    }
    i = i + 1;
  } while( true );
}

