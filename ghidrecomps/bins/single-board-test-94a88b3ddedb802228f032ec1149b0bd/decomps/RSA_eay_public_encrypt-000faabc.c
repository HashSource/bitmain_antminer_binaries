
size_t RSA_eay_public_encrypt(int param_1,uchar *param_2,int param_3,int param_4,undefined4 param_5)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  int iVar4;
  uchar *to;
  BIGNUM *pBVar5;
  BN_MONT_CTX *pBVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  size_t sVar10;
  size_t len;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  
  iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (0x4000 < iVar3) {
    ERR_put_error(4,0x68,0x69,DAT_000fae58,0xa4);
    return 0xffffffff;
  }
  iVar3 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar3 < 1) {
    iVar3 = 0xa9;
LAB_000fab5a:
    ERR_put_error(4,0x68,0x65,DAT_000fac68,iVar3);
    return 0xffffffff;
  }
  iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if ((0xc00 < iVar3) && (iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), 0x40 < iVar3)) {
    iVar3 = 0xb0;
    goto LAB_000fab5a;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0xffffffff;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  a = BN_CTX_get(ctx);
  iVar4 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar3 = iVar4 + 0xe;
  if (-1 < iVar4 + 7) {
    iVar3 = iVar4 + 7;
  }
  len = iVar3 >> 3;
  to = (uchar *)CRYPTO_malloc(len,DAT_000fac68,0xbb);
  if ((ret == (BIGNUM *)0x0 || a == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    sVar10 = 0xffffffff;
    ERR_put_error(4,0x68,0x41,DAT_000fac68,0xbd);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return 0xffffffff;
    }
    goto LAB_000fab90;
  }
  switch(param_5) {
  case 1:
    iVar3 = RSA_padding_add_PKCS1_type_2(to,len,param_2,param_1);
    break;
  case 2:
    iVar3 = RSA_padding_add_SSLv23(to,len,param_2,param_1);
    break;
  case 3:
    iVar3 = RSA_padding_add_none(to,len,param_2,param_1);
    break;
  case 4:
    iVar3 = RSA_padding_add_PKCS1_OAEP(to,len,param_2,param_1,(uchar *)0x0,0);
    break;
  default:
    ERR_put_error(4,0x68,0x76,DAT_000fac68,0xd1);
    sVar10 = 0xffffffff;
    goto LAB_000fabe8;
  }
  if ((iVar3 < 1) || (pBVar5 = BN_bin2bn(to,len,ret), pBVar5 == (BIGNUM *)0x0)) {
LAB_000fac62:
    sVar10 = 0xffffffff;
  }
  else {
    iVar3 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
    if (iVar3 < 0) {
      if (((*(int *)(param_4 + 0x3c) << 0x1e < 0) &&
          (pBVar6 = BN_MONT_CTX_set_locked
                              ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),ctx),
          pBVar6 == (BN_MONT_CTX *)0x0)) ||
         (iVar3 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                            (a,ret,*(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x10),
                             ctx,*(undefined4 *)(param_4 + 0x40)), iVar3 == 0)) goto LAB_000fac62;
      iVar4 = BN_num_bits(a);
      iVar3 = iVar4 + 0xe;
      if (-1 < iVar4 + 7) {
        iVar3 = iVar4 + 7;
      }
      iVar3 = BN_bn2bin(a,(uchar *)((len - (iVar3 >> 3)) + param_3));
      uVar7 = len - iVar3;
      sVar10 = len;
      if (0 < (int)uVar7) {
        uVar12 = -param_3 & 3U;
        if (uVar7 < (-param_3 & 3U)) {
          uVar12 = uVar7;
        }
        if (uVar7 < 4) {
          uVar12 = uVar7;
        }
        if (uVar12 == 0) {
          uVar9 = 0;
        }
        else {
          if (uVar12 < 0x21) {
            uVar9 = 0;
          }
          else {
            iVar3 = param_3;
            uVar8 = 0;
            do {
              *(undefined *)(param_3 + uVar8) = 0;
              HintPreloadData(param_3 + 0x22 + uVar8);
              uVar9 = uVar8 + 0x20;
              *(undefined *)(iVar3 + 1) = 0;
              uVar13 = uVar8 + 0x21;
              *(undefined *)(iVar3 + 2) = 0;
              *(undefined *)(iVar3 + 3) = 0;
              *(undefined *)(iVar3 + 4) = 0;
              *(undefined *)(iVar3 + 5) = 0;
              *(undefined *)(iVar3 + 6) = 0;
              *(undefined *)(iVar3 + 7) = 0;
              *(undefined *)(iVar3 + 8) = 0;
              *(undefined *)(iVar3 + 9) = 0;
              *(undefined *)(iVar3 + 10) = 0;
              *(undefined *)(iVar3 + 0xb) = 0;
              *(undefined *)(iVar3 + 0xc) = 0;
              *(undefined *)(iVar3 + 0xd) = 0;
              *(undefined *)(iVar3 + 0xe) = 0;
              *(undefined *)(iVar3 + 0xf) = 0;
              *(undefined *)(iVar3 + 0x10) = 0;
              *(undefined *)(iVar3 + 0x11) = 0;
              *(undefined *)(iVar3 + 0x12) = 0;
              *(undefined *)(iVar3 + 0x13) = 0;
              *(undefined *)(iVar3 + 0x14) = 0;
              *(undefined *)(iVar3 + 0x15) = 0;
              *(undefined *)(iVar3 + 0x16) = 0;
              *(undefined *)(iVar3 + 0x17) = 0;
              *(undefined *)(iVar3 + 0x18) = 0;
              *(undefined *)(iVar3 + 0x19) = 0;
              *(undefined *)(iVar3 + 0x1a) = 0;
              *(undefined *)(iVar3 + 0x1b) = 0;
              *(undefined *)(iVar3 + 0x1c) = 0;
              *(undefined *)(iVar3 + 0x1d) = 0;
              *(undefined *)(iVar3 + 0x1e) = 0;
              *(undefined *)(iVar3 + 0x1f) = 0;
              iVar3 = iVar3 + 0x20;
              uVar8 = uVar9;
            } while (uVar13 < uVar12 - 0x1f);
          }
          do {
            *(undefined *)(param_3 + uVar9) = 0;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar12);
          if (uVar7 == uVar12) goto LAB_000fabe8;
        }
        uVar8 = uVar7 - uVar12;
        uVar13 = uVar8 >> 2;
        if (uVar13 != 0) {
          puVar14 = (undefined4 *)(param_3 + uVar12);
          if (uVar13 < 9) {
            uVar12 = 0;
          }
          else {
            uVar12 = 0;
            puVar2 = puVar14;
            do {
              puVar14 = puVar2 + 8;
              uVar11 = uVar12 + 9;
              uVar12 = uVar12 + 8;
              HintPreloadData(puVar2 + 0x28);
              *puVar2 = 0;
              puVar2[1] = 0;
              puVar2[2] = 0;
              puVar2[3] = 0;
              puVar2[4] = 0;
              puVar2[5] = 0;
              puVar2[6] = 0;
              puVar2[7] = 0;
              puVar2 = puVar14;
            } while (uVar11 < uVar13 - 7);
          }
          do {
            uVar12 = uVar12 + 1;
            *puVar14 = 0;
            puVar14 = puVar14 + 1;
          } while (uVar12 < uVar13);
          uVar9 = uVar9 + (uVar8 & 0xfffffffc);
          if (uVar8 == (uVar8 & 0xfffffffc)) goto LAB_000fabe8;
        }
        uVar12 = uVar9 + 1;
        if ((int)uVar12 < (int)(uVar7 - 0x1f) && (int)uVar9 < (int)uVar7) {
          iVar3 = param_3 + uVar9;
          uVar8 = uVar9;
          do {
            *(undefined *)(param_3 + uVar8) = 0;
            HintPreloadData(param_3 + 0x28 + uVar8);
            uVar9 = uVar8 + 0x20;
            *(undefined *)(iVar3 + 1) = 0;
            uVar12 = uVar8 + 0x21;
            *(undefined *)(iVar3 + 2) = 0;
            *(undefined *)(iVar3 + 3) = 0;
            *(undefined *)(iVar3 + 4) = 0;
            *(undefined *)(iVar3 + 5) = 0;
            *(undefined *)(iVar3 + 6) = 0;
            *(undefined *)(iVar3 + 7) = 0;
            *(undefined *)(iVar3 + 8) = 0;
            *(undefined *)(iVar3 + 9) = 0;
            *(undefined *)(iVar3 + 10) = 0;
            *(undefined *)(iVar3 + 0xb) = 0;
            *(undefined *)(iVar3 + 0xc) = 0;
            *(undefined *)(iVar3 + 0xd) = 0;
            *(undefined *)(iVar3 + 0xe) = 0;
            *(undefined *)(iVar3 + 0xf) = 0;
            *(undefined *)(iVar3 + 0x10) = 0;
            *(undefined *)(iVar3 + 0x11) = 0;
            *(undefined *)(iVar3 + 0x12) = 0;
            *(undefined *)(iVar3 + 0x13) = 0;
            *(undefined *)(iVar3 + 0x14) = 0;
            *(undefined *)(iVar3 + 0x15) = 0;
            *(undefined *)(iVar3 + 0x16) = 0;
            *(undefined *)(iVar3 + 0x17) = 0;
            *(undefined *)(iVar3 + 0x18) = 0;
            *(undefined *)(iVar3 + 0x19) = 0;
            *(undefined *)(iVar3 + 0x1a) = 0;
            *(undefined *)(iVar3 + 0x1b) = 0;
            *(undefined *)(iVar3 + 0x1c) = 0;
            *(undefined *)(iVar3 + 0x1d) = 0;
            *(undefined *)(iVar3 + 0x1e) = 0;
            *(undefined *)(iVar3 + 0x1f) = 0;
            iVar3 = iVar3 + 0x20;
            uVar8 = uVar9;
          } while ((int)uVar12 < (int)(uVar7 - 0x1f));
        }
        do {
          *(undefined *)(param_3 + uVar9) = 0;
          bVar1 = (int)uVar12 < (int)uVar7;
          uVar9 = uVar12;
          uVar12 = uVar12 + 1;
        } while (bVar1);
      }
    }
    else {
      ERR_put_error(4,0x68,0x84,DAT_000fac68,0xdd);
      sVar10 = 0xffffffff;
    }
  }
LAB_000fabe8:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_000fab90:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return sVar10;
}

