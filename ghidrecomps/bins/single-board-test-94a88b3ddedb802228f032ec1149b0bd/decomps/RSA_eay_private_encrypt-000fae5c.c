
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
  ulong **ppuVar7;
  uint uVar8;
  uint uVar9;
  size_t sVar10;
  uint uVar11;
  size_t len;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  BN_BLINDING *b;
  uint uVar15;
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
  to = (uchar *)CRYPTO_malloc(len,DAT_000fb16c,0x172);
  if ((ret == (BIGNUM *)0x0 || n == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    sVar10 = 0xffffffff;
    ERR_put_error(4,0x66,0x41,DAT_000fb304,0x174);
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
      sVar10 = 0xffffffff;
    }
    else {
      iVar6 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
      if (iVar6 < 0) {
        uVar8 = *(uint *)(param_4 + 0x3c);
        if ((uVar8 & 0x80) == 0) {
          b = (BN_BLINDING *)rsa_get_blinding(param_4,&local_40,ctx);
          if (b == (BN_BLINDING *)0x0) {
            ERR_put_error(4,0x66,0x44,DAT_000fb304,0x197);
            sVar10 = 0xffffffff;
            goto LAB_000faeea;
          }
          if (local_40 == 0) {
            local_44 = BN_CTX_get(ctx);
            if (local_44 == (BIGNUM *)0x0) {
              ERR_put_error(4,0x66,0x41,DAT_000fb304,0x19e);
              sVar10 = 0xffffffff;
              goto LAB_000faeea;
            }
            CRYPTO_lock(9,0x19,DAT_000fb304,0x146);
            iVar6 = BN_BLINDING_convert_ex(ret,local_44,b,ctx);
            CRYPTO_lock(10,0x19,DAT_000fb304,0x148);
          }
          else {
            iVar6 = BN_BLINDING_convert_ex(ret,(BIGNUM *)0x0,b,ctx);
            local_44 = (BIGNUM *)0x0;
          }
          if (iVar6 == 0) goto LAB_000fb1a8;
          uVar8 = *(uint *)(param_4 + 0x3c);
        }
        else {
          b = (BN_BLINDING *)0x0;
          local_44 = (BIGNUM *)0x0;
        }
        if (((int)(uVar8 << 0x1a) < 0) ||
           ((((*(int *)(param_4 + 0x1c) != 0 && (*(int *)(param_4 + 0x20) != 0)) &&
             (*(int *)(param_4 + 0x24) != 0)) &&
            ((*(int *)(param_4 + 0x28) != 0 && (*(int *)(param_4 + 0x2c) != 0)))))) {
          iVar6 = (**(code **)(*(int *)(param_4 + 8) + 0x14))(n,ret,param_4,ctx);
        }
        else {
          if ((int)(uVar8 << 0x17) < 0) {
            pBVar4 = *(BIGNUM **)(param_4 + 0x18);
          }
          else {
            pBVar4 = &local_3c;
            BN_init(pBVar4);
            ppuVar7 = *(ulong ***)(param_4 + 0x18);
            uVar8 = *(uint *)(param_4 + 0x3c);
            local_3c.d = *ppuVar7;
            local_3c.top = (int)ppuVar7[1];
            local_3c.dmax = (int)ppuVar7[2];
            local_3c.neg = (int)ppuVar7[3];
            local_3c.flags = local_3c.flags & 1U | (uint)ppuVar7[4] & 0xfffffffe | 6;
          }
          if (((int)(uVar8 << 0x1e) < 0) &&
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
        uVar8 = len - iVar6;
        sVar10 = len;
        if (0 < (int)uVar8) {
          uVar15 = -param_3 & 3U;
          if (uVar8 < (-param_3 & 3U)) {
            uVar15 = uVar8;
          }
          if (uVar8 < 4) {
            uVar15 = uVar8;
          }
          if (uVar15 == 0) {
            uVar9 = 0;
          }
          else {
            if (uVar15 < 0x21) {
              uVar9 = 0;
            }
            else {
              iVar6 = param_3;
              uVar13 = 0;
              do {
                *(undefined *)(param_3 + uVar13) = 0;
                HintPreloadData(param_3 + 0x22 + uVar13);
                uVar9 = uVar13 + 0x20;
                *(undefined *)(iVar6 + 1) = 0;
                uVar11 = uVar13 + 0x21;
                *(undefined *)(iVar6 + 2) = 0;
                *(undefined *)(iVar6 + 3) = 0;
                *(undefined *)(iVar6 + 4) = 0;
                *(undefined *)(iVar6 + 5) = 0;
                *(undefined *)(iVar6 + 6) = 0;
                *(undefined *)(iVar6 + 7) = 0;
                *(undefined *)(iVar6 + 8) = 0;
                *(undefined *)(iVar6 + 9) = 0;
                *(undefined *)(iVar6 + 10) = 0;
                *(undefined *)(iVar6 + 0xb) = 0;
                *(undefined *)(iVar6 + 0xc) = 0;
                *(undefined *)(iVar6 + 0xd) = 0;
                *(undefined *)(iVar6 + 0xe) = 0;
                *(undefined *)(iVar6 + 0xf) = 0;
                *(undefined *)(iVar6 + 0x10) = 0;
                *(undefined *)(iVar6 + 0x11) = 0;
                *(undefined *)(iVar6 + 0x12) = 0;
                *(undefined *)(iVar6 + 0x13) = 0;
                *(undefined *)(iVar6 + 0x14) = 0;
                *(undefined *)(iVar6 + 0x15) = 0;
                *(undefined *)(iVar6 + 0x16) = 0;
                *(undefined *)(iVar6 + 0x17) = 0;
                *(undefined *)(iVar6 + 0x18) = 0;
                *(undefined *)(iVar6 + 0x19) = 0;
                *(undefined *)(iVar6 + 0x1a) = 0;
                *(undefined *)(iVar6 + 0x1b) = 0;
                *(undefined *)(iVar6 + 0x1c) = 0;
                *(undefined *)(iVar6 + 0x1d) = 0;
                *(undefined *)(iVar6 + 0x1e) = 0;
                *(undefined *)(iVar6 + 0x1f) = 0;
                iVar6 = iVar6 + 0x20;
                uVar13 = uVar9;
              } while (uVar11 < uVar15 - 0x1f);
            }
            do {
              *(undefined *)(param_3 + uVar9) = 0;
              uVar9 = uVar9 + 1;
            } while (uVar9 < uVar15);
            if (uVar8 == uVar15) goto LAB_000faeea;
          }
          uVar11 = uVar8 - uVar15;
          uVar13 = uVar11 >> 2;
          if (uVar13 != 0) {
            puVar12 = (undefined4 *)(uVar15 + param_3);
            if (uVar13 < 9) {
              uVar15 = 0;
            }
            else {
              uVar15 = 0;
              puVar2 = puVar12;
              do {
                puVar12 = puVar2 + 8;
                uVar14 = uVar15 + 9;
                uVar15 = uVar15 + 8;
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
              uVar15 = uVar15 + 1;
              *puVar12 = 0;
              puVar12 = puVar12 + 1;
            } while (uVar15 < uVar13);
            uVar9 = uVar9 + (uVar11 & 0xfffffffc);
            if (uVar11 == (uVar11 & 0xfffffffc)) goto LAB_000faeea;
          }
          uVar15 = uVar9 + 1;
          if ((int)uVar15 < (int)(uVar8 - 0x1f) && (int)uVar9 < (int)uVar8) {
            iVar6 = param_3 + uVar9;
            uVar13 = uVar9;
            do {
              *(undefined *)(param_3 + uVar13) = 0;
              HintPreloadData(param_3 + 0x28 + uVar13);
              uVar9 = uVar13 + 0x20;
              *(undefined *)(iVar6 + 1) = 0;
              uVar15 = uVar13 + 0x21;
              *(undefined *)(iVar6 + 2) = 0;
              *(undefined *)(iVar6 + 3) = 0;
              *(undefined *)(iVar6 + 4) = 0;
              *(undefined *)(iVar6 + 5) = 0;
              *(undefined *)(iVar6 + 6) = 0;
              *(undefined *)(iVar6 + 7) = 0;
              *(undefined *)(iVar6 + 8) = 0;
              *(undefined *)(iVar6 + 9) = 0;
              *(undefined *)(iVar6 + 10) = 0;
              *(undefined *)(iVar6 + 0xb) = 0;
              *(undefined *)(iVar6 + 0xc) = 0;
              *(undefined *)(iVar6 + 0xd) = 0;
              *(undefined *)(iVar6 + 0xe) = 0;
              *(undefined *)(iVar6 + 0xf) = 0;
              *(undefined *)(iVar6 + 0x10) = 0;
              *(undefined *)(iVar6 + 0x11) = 0;
              *(undefined *)(iVar6 + 0x12) = 0;
              *(undefined *)(iVar6 + 0x13) = 0;
              *(undefined *)(iVar6 + 0x14) = 0;
              *(undefined *)(iVar6 + 0x15) = 0;
              *(undefined *)(iVar6 + 0x16) = 0;
              *(undefined *)(iVar6 + 0x17) = 0;
              *(undefined *)(iVar6 + 0x18) = 0;
              *(undefined *)(iVar6 + 0x19) = 0;
              *(undefined *)(iVar6 + 0x1a) = 0;
              *(undefined *)(iVar6 + 0x1b) = 0;
              *(undefined *)(iVar6 + 0x1c) = 0;
              *(undefined *)(iVar6 + 0x1d) = 0;
              *(undefined *)(iVar6 + 0x1e) = 0;
              *(undefined *)(iVar6 + 0x1f) = 0;
              iVar6 = iVar6 + 0x20;
              uVar13 = uVar9;
            } while ((int)uVar15 < (int)(uVar8 - 0x1f));
          }
          do {
            *(undefined *)(param_3 + uVar9) = 0;
            bVar1 = (int)uVar15 < (int)uVar8;
            uVar9 = uVar15;
            uVar15 = uVar15 + 1;
          } while (bVar1);
        }
      }
      else {
        ERR_put_error(4,0x66,0x84,DAT_000fb304,400);
        sVar10 = 0xffffffff;
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
    ERR_put_error(4,0x66,0x76,DAT_000fb16c,0x184);
    sVar10 = 0xffffffff;
  }
LAB_000faeea:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_000faef6:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return sVar10;
}

