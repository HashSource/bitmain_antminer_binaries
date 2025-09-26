
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
  size_t sVar9;
  uint uVar10;
  size_t len;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  
  iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (0x4000 < iVar3) {
    ERR_put_error(4,0x68,0x69,"rsa_eay.c",0xa4);
    return 0xffffffff;
  }
  iVar3 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar3 < 1) {
    iVar3 = 0xa9;
LAB_001932ba:
    ERR_put_error(4,0x68,0x65,"rsa_eay.c",iVar3);
    return 0xffffffff;
  }
  iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if ((0xc00 < iVar3) && (iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), 0x40 < iVar3)) {
    iVar3 = 0xb0;
    goto LAB_001932ba;
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
  to = (uchar *)CRYPTO_malloc(len,"rsa_eay.c",0xbb);
  if ((ret == (BIGNUM *)0x0 || a == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    sVar9 = 0xffffffff;
    ERR_put_error(4,0x68,0x41,"rsa_eay.c",0xbd);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return 0xffffffff;
    }
    goto LAB_001932f0;
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
    ERR_put_error(4,0x68,0x76,"rsa_eay.c",0xd1);
    sVar9 = 0xffffffff;
    goto LAB_00193348;
  }
  if ((iVar3 < 1) || (pBVar5 = BN_bin2bn(to,len,ret), pBVar5 == (BIGNUM *)0x0)) {
LAB_001933c2:
    sVar9 = 0xffffffff;
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
                             ctx,*(undefined4 *)(param_4 + 0x40)), iVar3 == 0)) goto LAB_001933c2;
      iVar4 = BN_num_bits(a);
      iVar3 = iVar4 + 0xe;
      if (-1 < iVar4 + 7) {
        iVar3 = iVar4 + 7;
      }
      iVar3 = BN_bn2bin(a,(uchar *)((len - (iVar3 >> 3)) + param_3));
      uVar7 = len - iVar3;
      sVar9 = len;
      if (0 < (int)uVar7) {
        uVar10 = -param_3 & 3U;
        if (uVar7 < (-param_3 & 3U)) {
          uVar10 = uVar7;
        }
        if (uVar7 < 4) {
          uVar10 = uVar7;
        }
        if (uVar10 == 0) {
          uVar8 = 0;
        }
        else {
          if (uVar10 < 0x21) {
            uVar8 = 0;
          }
          else {
            iVar3 = param_3;
            uVar11 = 0;
            do {
              *(undefined1 *)(param_3 + uVar11) = 0;
              HintPreloadData(param_3 + 0x22 + uVar11);
              uVar8 = uVar11 + 0x20;
              *(undefined1 *)(iVar3 + 1) = 0;
              uVar13 = uVar11 + 0x21;
              *(undefined1 *)(iVar3 + 2) = 0;
              *(undefined1 *)(iVar3 + 3) = 0;
              *(undefined1 *)(iVar3 + 4) = 0;
              *(undefined1 *)(iVar3 + 5) = 0;
              *(undefined1 *)(iVar3 + 6) = 0;
              *(undefined1 *)(iVar3 + 7) = 0;
              *(undefined1 *)(iVar3 + 8) = 0;
              *(undefined1 *)(iVar3 + 9) = 0;
              *(undefined1 *)(iVar3 + 10) = 0;
              *(undefined1 *)(iVar3 + 0xb) = 0;
              *(undefined1 *)(iVar3 + 0xc) = 0;
              *(undefined1 *)(iVar3 + 0xd) = 0;
              *(undefined1 *)(iVar3 + 0xe) = 0;
              *(undefined1 *)(iVar3 + 0xf) = 0;
              *(undefined1 *)(iVar3 + 0x10) = 0;
              *(undefined1 *)(iVar3 + 0x11) = 0;
              *(undefined1 *)(iVar3 + 0x12) = 0;
              *(undefined1 *)(iVar3 + 0x13) = 0;
              *(undefined1 *)(iVar3 + 0x14) = 0;
              *(undefined1 *)(iVar3 + 0x15) = 0;
              *(undefined1 *)(iVar3 + 0x16) = 0;
              *(undefined1 *)(iVar3 + 0x17) = 0;
              *(undefined1 *)(iVar3 + 0x18) = 0;
              *(undefined1 *)(iVar3 + 0x19) = 0;
              *(undefined1 *)(iVar3 + 0x1a) = 0;
              *(undefined1 *)(iVar3 + 0x1b) = 0;
              *(undefined1 *)(iVar3 + 0x1c) = 0;
              *(undefined1 *)(iVar3 + 0x1d) = 0;
              *(undefined1 *)(iVar3 + 0x1e) = 0;
              *(undefined1 *)(iVar3 + 0x1f) = 0;
              iVar3 = iVar3 + 0x20;
              uVar11 = uVar8;
            } while (uVar13 < uVar10 - 0x1f);
          }
          do {
            *(undefined1 *)(param_3 + uVar8) = 0;
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar10);
          if (uVar7 == uVar10) goto LAB_00193348;
        }
        uVar11 = uVar7 - uVar10 >> 2;
        if (uVar11 != 0) {
          puVar14 = (undefined4 *)(param_3 + uVar10);
          if (uVar11 < 9) {
            uVar13 = 0;
          }
          else {
            uVar13 = 0;
            puVar2 = puVar14;
            do {
              puVar14 = puVar2 + 8;
              uVar12 = uVar13 + 9;
              uVar13 = uVar13 + 8;
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
            } while (uVar12 < uVar11 - 7);
          }
          do {
            uVar13 = uVar13 + 1;
            *puVar14 = 0;
            puVar14 = puVar14 + 1;
          } while (uVar13 < uVar11);
          uVar8 = uVar8 + uVar11 * 4;
          if (uVar7 - uVar10 == uVar11 * 4) goto LAB_00193348;
        }
        uVar10 = uVar8 + 1;
        if ((int)uVar10 < (int)(uVar7 - 0x1f) && (int)uVar8 < (int)uVar7) {
          iVar3 = param_3 + uVar8;
          uVar11 = uVar8;
          do {
            *(undefined1 *)(param_3 + uVar11) = 0;
            HintPreloadData(param_3 + 0x28 + uVar11);
            uVar8 = uVar11 + 0x20;
            *(undefined1 *)(iVar3 + 1) = 0;
            uVar10 = uVar11 + 0x21;
            *(undefined1 *)(iVar3 + 2) = 0;
            *(undefined1 *)(iVar3 + 3) = 0;
            *(undefined1 *)(iVar3 + 4) = 0;
            *(undefined1 *)(iVar3 + 5) = 0;
            *(undefined1 *)(iVar3 + 6) = 0;
            *(undefined1 *)(iVar3 + 7) = 0;
            *(undefined1 *)(iVar3 + 8) = 0;
            *(undefined1 *)(iVar3 + 9) = 0;
            *(undefined1 *)(iVar3 + 10) = 0;
            *(undefined1 *)(iVar3 + 0xb) = 0;
            *(undefined1 *)(iVar3 + 0xc) = 0;
            *(undefined1 *)(iVar3 + 0xd) = 0;
            *(undefined1 *)(iVar3 + 0xe) = 0;
            *(undefined1 *)(iVar3 + 0xf) = 0;
            *(undefined1 *)(iVar3 + 0x10) = 0;
            *(undefined1 *)(iVar3 + 0x11) = 0;
            *(undefined1 *)(iVar3 + 0x12) = 0;
            *(undefined1 *)(iVar3 + 0x13) = 0;
            *(undefined1 *)(iVar3 + 0x14) = 0;
            *(undefined1 *)(iVar3 + 0x15) = 0;
            *(undefined1 *)(iVar3 + 0x16) = 0;
            *(undefined1 *)(iVar3 + 0x17) = 0;
            *(undefined1 *)(iVar3 + 0x18) = 0;
            *(undefined1 *)(iVar3 + 0x19) = 0;
            *(undefined1 *)(iVar3 + 0x1a) = 0;
            *(undefined1 *)(iVar3 + 0x1b) = 0;
            *(undefined1 *)(iVar3 + 0x1c) = 0;
            *(undefined1 *)(iVar3 + 0x1d) = 0;
            *(undefined1 *)(iVar3 + 0x1e) = 0;
            *(undefined1 *)(iVar3 + 0x1f) = 0;
            iVar3 = iVar3 + 0x20;
            uVar11 = uVar8;
          } while ((int)uVar10 < (int)(uVar7 - 0x1f));
        }
        do {
          *(undefined1 *)(param_3 + uVar8) = 0;
          bVar1 = (int)uVar10 < (int)uVar7;
          uVar8 = uVar10;
          uVar10 = uVar10 + 1;
        } while (bVar1);
      }
    }
    else {
      ERR_put_error(4,0x68,0x84,"rsa_eay.c",0xdd);
      sVar9 = 0xffffffff;
    }
  }
LAB_00193348:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_001932f0:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return sVar9;
}

