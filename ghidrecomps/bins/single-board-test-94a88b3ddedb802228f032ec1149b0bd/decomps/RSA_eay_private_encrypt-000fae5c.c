
size_t RSA_eay_private_encrypt(int param_1,uchar *param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  undefined4 *puVar2;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *n;
  int iVar3;
  uchar *to;
  BIGNUM *pBVar4;
  BN_MONT_CTX *pBVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  uint uVar10;
  uint uVar11;
  size_t len;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  BN_BLINDING *b;
  BIGNUM *local_44;
  int local_40;
  BIGNUM local_3c;
  
  local_40 = 0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0xffffffff;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  n = BN_CTX_get(ctx);
  iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar6 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar6 = iVar3 + 7;
  }
  len = iVar6 >> 3;
  to = (uchar *)CRYPTO_malloc(len,"rsa_eay.c",0x172);
  if ((ret == (BIGNUM *)0x0 || n == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    sVar9 = 0xffffffff;
    ERR_put_error(4,0x66,0x41,"rsa_eay.c",0x174);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return 0xffffffff;
    }
    goto LAB_000faef6;
  }
  if (param_5 == 3) {
    iVar6 = RSA_padding_add_none(to,len,param_2,param_1);
LAB_000faf16:
    if ((iVar6 < 1) || (pBVar4 = BN_bin2bn(to,len,ret), pBVar4 == (BIGNUM *)0x0)) {
LAB_000fb1a8:
      sVar9 = 0xffffffff;
    }
    else {
      iVar6 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
      if (iVar6 < 0) {
        uVar7 = *(uint *)(param_4 + 0x3c);
        if ((uVar7 & 0x80) == 0) {
          b = (BN_BLINDING *)rsa_get_blinding(param_4,&local_40,ctx);
          if (b == (BN_BLINDING *)0x0) {
            ERR_put_error(4,0x66,0x44,"rsa_eay.c",0x197);
            sVar9 = 0xffffffff;
            goto LAB_000faeea;
          }
          if (local_40 == 0) {
            local_44 = BN_CTX_get(ctx);
            if (local_44 == (BIGNUM *)0x0) {
              ERR_put_error(4,0x66,0x41,"rsa_eay.c",0x19e);
              sVar9 = 0xffffffff;
              goto LAB_000faeea;
            }
            CRYPTO_lock(9,0x19,"rsa_eay.c",0x146);
            iVar6 = BN_BLINDING_convert_ex(ret,local_44,b,ctx);
            CRYPTO_lock(10,0x19,"rsa_eay.c",0x148);
          }
          else {
            iVar6 = BN_BLINDING_convert_ex(ret,(BIGNUM *)0x0,b,ctx);
            local_44 = (BIGNUM *)0x0;
          }
          if (iVar6 == 0) goto LAB_000fb1a8;
          uVar7 = *(uint *)(param_4 + 0x3c);
        }
        else {
          b = (BN_BLINDING *)0x0;
          local_44 = (BIGNUM *)0x0;
        }
        if (((int)(uVar7 << 0x1a) < 0) ||
           ((((*(int *)(param_4 + 0x1c) != 0 && (*(int *)(param_4 + 0x20) != 0)) &&
             (*(int *)(param_4 + 0x24) != 0)) &&
            ((*(int *)(param_4 + 0x28) != 0 && (*(int *)(param_4 + 0x2c) != 0)))))) {
          iVar6 = (**(code **)(*(int *)(param_4 + 8) + 0x14))(n,ret,param_4,ctx);
        }
        else {
          if ((int)(uVar7 << 0x17) < 0) {
            pBVar4 = *(BIGNUM **)(param_4 + 0x18);
          }
          else {
            pBVar4 = &local_3c;
            BN_init(pBVar4);
            puVar12 = *(undefined4 **)(param_4 + 0x18);
            uVar7 = *(uint *)(param_4 + 0x3c);
            local_3c.d = (ulong *)*puVar12;
            local_3c.top = puVar12[1];
            local_3c.dmax = puVar12[2];
            local_3c.neg = puVar12[3];
            local_3c.flags = local_3c.flags & 1U | puVar12[4] & 0xfffffffe | 6;
          }
          if (((int)(uVar7 << 0x1e) < 0) &&
             (pBVar5 = BN_MONT_CTX_set_locked
                                 ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),
                                  ctx), pBVar5 == (BN_MONT_CTX *)0x0)) goto LAB_000fb1a8;
          iVar6 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                            (n,ret,pBVar4,*(undefined4 *)(param_4 + 0x10),ctx,
                             *(undefined4 *)(param_4 + 0x40));
        }
        if ((iVar6 == 0) ||
           ((b != (BN_BLINDING *)0x0 &&
            (iVar6 = BN_BLINDING_invert_ex(n,local_44,b,ctx), iVar6 == 0)))) goto LAB_000fb1a8;
        if (param_5 == 5) {
          BN_sub(ret,*(BIGNUM **)(param_4 + 0x10),n);
          iVar6 = BN_cmp(n,ret);
          if (0 < iVar6) {
            n = ret;
          }
        }
        iVar3 = BN_num_bits(n);
        iVar6 = iVar3 + 0xe;
        if (-1 < iVar3 + 7) {
          iVar6 = iVar3 + 7;
        }
        iVar6 = BN_bn2bin(n,(uchar *)((len - (iVar6 >> 3)) + param_3));
        uVar7 = len - iVar6;
        sVar9 = len;
        if (0 < (int)uVar7) {
          uVar11 = -param_3 & 3U;
          if (uVar7 < (-param_3 & 3U)) {
            uVar11 = uVar7;
          }
          if (uVar7 < 4) {
            uVar11 = uVar7;
          }
          if (uVar11 == 0) {
            uVar8 = 0;
          }
          else {
            if (uVar11 < 0x21) {
              uVar8 = 0;
            }
            else {
              iVar6 = param_3;
              uVar13 = 0;
              do {
                *(undefined1 *)(param_3 + uVar13) = 0;
                HintPreloadData(param_3 + 0x22 + uVar13);
                uVar8 = uVar13 + 0x20;
                *(undefined1 *)(iVar6 + 1) = 0;
                uVar10 = uVar13 + 0x21;
                *(undefined1 *)(iVar6 + 2) = 0;
                *(undefined1 *)(iVar6 + 3) = 0;
                *(undefined1 *)(iVar6 + 4) = 0;
                *(undefined1 *)(iVar6 + 5) = 0;
                *(undefined1 *)(iVar6 + 6) = 0;
                *(undefined1 *)(iVar6 + 7) = 0;
                *(undefined1 *)(iVar6 + 8) = 0;
                *(undefined1 *)(iVar6 + 9) = 0;
                *(undefined1 *)(iVar6 + 10) = 0;
                *(undefined1 *)(iVar6 + 0xb) = 0;
                *(undefined1 *)(iVar6 + 0xc) = 0;
                *(undefined1 *)(iVar6 + 0xd) = 0;
                *(undefined1 *)(iVar6 + 0xe) = 0;
                *(undefined1 *)(iVar6 + 0xf) = 0;
                *(undefined1 *)(iVar6 + 0x10) = 0;
                *(undefined1 *)(iVar6 + 0x11) = 0;
                *(undefined1 *)(iVar6 + 0x12) = 0;
                *(undefined1 *)(iVar6 + 0x13) = 0;
                *(undefined1 *)(iVar6 + 0x14) = 0;
                *(undefined1 *)(iVar6 + 0x15) = 0;
                *(undefined1 *)(iVar6 + 0x16) = 0;
                *(undefined1 *)(iVar6 + 0x17) = 0;
                *(undefined1 *)(iVar6 + 0x18) = 0;
                *(undefined1 *)(iVar6 + 0x19) = 0;
                *(undefined1 *)(iVar6 + 0x1a) = 0;
                *(undefined1 *)(iVar6 + 0x1b) = 0;
                *(undefined1 *)(iVar6 + 0x1c) = 0;
                *(undefined1 *)(iVar6 + 0x1d) = 0;
                *(undefined1 *)(iVar6 + 0x1e) = 0;
                *(undefined1 *)(iVar6 + 0x1f) = 0;
                iVar6 = iVar6 + 0x20;
                uVar13 = uVar8;
              } while (uVar10 < uVar11 - 0x1f);
            }
            do {
              *(undefined1 *)(param_3 + uVar8) = 0;
              uVar8 = uVar8 + 1;
            } while (uVar8 < uVar11);
            if (uVar7 == uVar11) goto LAB_000faeea;
          }
          uVar13 = uVar7 - uVar11 >> 2;
          if (uVar13 != 0) {
            puVar12 = (undefined4 *)(uVar11 + param_3);
            if (uVar13 < 9) {
              uVar10 = 0;
            }
            else {
              uVar10 = 0;
              puVar2 = puVar12;
              do {
                puVar12 = puVar2 + 8;
                uVar14 = uVar10 + 9;
                uVar10 = uVar10 + 8;
                HintPreloadData(puVar2 + 0x28);
                *puVar2 = 0;
                puVar2[1] = 0;
                puVar2[2] = 0;
                puVar2[3] = 0;
                puVar2[4] = 0;
                puVar2[5] = 0;
                puVar2[6] = 0;
                puVar2[7] = 0;
                puVar2 = puVar12;
              } while (uVar14 < uVar13 - 7);
            }
            do {
              uVar10 = uVar10 + 1;
              *puVar12 = 0;
              puVar12 = puVar12 + 1;
            } while (uVar10 < uVar13);
            uVar8 = uVar8 + uVar13 * 4;
            if (uVar7 - uVar11 == uVar13 * 4) goto LAB_000faeea;
          }
          uVar11 = uVar8 + 1;
          if ((int)uVar11 < (int)(uVar7 - 0x1f) && (int)uVar8 < (int)uVar7) {
            iVar6 = param_3 + uVar8;
            uVar13 = uVar8;
            do {
              *(undefined1 *)(param_3 + uVar13) = 0;
              HintPreloadData(param_3 + 0x28 + uVar13);
              uVar8 = uVar13 + 0x20;
              *(undefined1 *)(iVar6 + 1) = 0;
              uVar11 = uVar13 + 0x21;
              *(undefined1 *)(iVar6 + 2) = 0;
              *(undefined1 *)(iVar6 + 3) = 0;
              *(undefined1 *)(iVar6 + 4) = 0;
              *(undefined1 *)(iVar6 + 5) = 0;
              *(undefined1 *)(iVar6 + 6) = 0;
              *(undefined1 *)(iVar6 + 7) = 0;
              *(undefined1 *)(iVar6 + 8) = 0;
              *(undefined1 *)(iVar6 + 9) = 0;
              *(undefined1 *)(iVar6 + 10) = 0;
              *(undefined1 *)(iVar6 + 0xb) = 0;
              *(undefined1 *)(iVar6 + 0xc) = 0;
              *(undefined1 *)(iVar6 + 0xd) = 0;
              *(undefined1 *)(iVar6 + 0xe) = 0;
              *(undefined1 *)(iVar6 + 0xf) = 0;
              *(undefined1 *)(iVar6 + 0x10) = 0;
              *(undefined1 *)(iVar6 + 0x11) = 0;
              *(undefined1 *)(iVar6 + 0x12) = 0;
              *(undefined1 *)(iVar6 + 0x13) = 0;
              *(undefined1 *)(iVar6 + 0x14) = 0;
              *(undefined1 *)(iVar6 + 0x15) = 0;
              *(undefined1 *)(iVar6 + 0x16) = 0;
              *(undefined1 *)(iVar6 + 0x17) = 0;
              *(undefined1 *)(iVar6 + 0x18) = 0;
              *(undefined1 *)(iVar6 + 0x19) = 0;
              *(undefined1 *)(iVar6 + 0x1a) = 0;
              *(undefined1 *)(iVar6 + 0x1b) = 0;
              *(undefined1 *)(iVar6 + 0x1c) = 0;
              *(undefined1 *)(iVar6 + 0x1d) = 0;
              *(undefined1 *)(iVar6 + 0x1e) = 0;
              *(undefined1 *)(iVar6 + 0x1f) = 0;
              iVar6 = iVar6 + 0x20;
              uVar13 = uVar8;
            } while ((int)uVar11 < (int)(uVar7 - 0x1f));
          }
          do {
            *(undefined1 *)(param_3 + uVar8) = 0;
            bVar1 = (int)uVar11 < (int)uVar7;
            uVar8 = uVar11;
            uVar11 = uVar11 + 1;
          } while (bVar1);
        }
      }
      else {
        ERR_put_error(4,0x66,0x84,"rsa_eay.c",400);
        sVar9 = 0xffffffff;
      }
    }
  }
  else {
    if (param_5 == 5) {
      iVar6 = RSA_padding_add_X931(to,len,param_2,param_1);
      goto LAB_000faf16;
    }
    if (param_5 == 1) {
      iVar6 = RSA_padding_add_PKCS1_type_1(to,len,param_2,param_1);
      goto LAB_000faf16;
    }
    ERR_put_error(4,0x66,0x76,"rsa_eay.c",0x184);
    sVar9 = 0xffffffff;
  }
LAB_000faeea:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_000faef6:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return sVar9;
}

