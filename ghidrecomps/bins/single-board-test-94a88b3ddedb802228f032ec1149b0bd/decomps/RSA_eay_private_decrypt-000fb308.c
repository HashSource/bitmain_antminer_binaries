
int RSA_eay_private_decrypt
              (int param_1,uchar *param_2,uchar *param_3,int param_4,undefined4 param_5)

{
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *n;
  int iVar1;
  uchar *to;
  BIGNUM *pBVar2;
  int iVar3;
  BN_MONT_CTX *pBVar4;
  BIGNUM *r;
  undefined4 *puVar5;
  uint uVar6;
  size_t len;
  undefined4 *puVar7;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  
  local_40 = 0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return -1;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  n = BN_CTX_get(ctx);
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar3 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar3 = iVar1 + 7;
  }
  len = iVar3 >> 3;
  to = (uchar *)CRYPTO_malloc(len,DAT_000fb5b4,0x1fa);
  r = (BIGNUM *)(uint)(ret == (BIGNUM *)0x0 || n == (BIGNUM *)0x0);
  if ((ret == (BIGNUM *)0x0 || n == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    iVar3 = -1;
    ERR_put_error(4,0x65,0x41,DAT_000fb618,0x1fc);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return -1;
    }
    goto LAB_000fb510;
  }
  if ((int)len < param_1) {
    ERR_put_error(4,0x65,0x6c,DAT_000fb5b4,0x206);
    iVar3 = -1;
  }
  else {
    pBVar2 = BN_bin2bn(param_2,param_1,ret);
    if (pBVar2 == (BIGNUM *)0x0) {
LAB_000fb44a:
      iVar3 = -1;
    }
    else {
      iVar3 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
      if (iVar3 < 0) {
        uVar6 = *(uint *)(param_4 + 0x3c);
        pBVar2 = r;
        if ((uVar6 & 0x80) == 0) {
          pBVar2 = (BIGNUM *)rsa_get_blinding(param_4,&local_40,ctx);
          if (pBVar2 == (BIGNUM *)0x0) {
            ERR_put_error(4,0x65,0x44,DAT_000fb618,0x217);
            iVar3 = -1;
            goto LAB_000fb504;
          }
          if (local_40 == 0) {
            r = BN_CTX_get(ctx);
            if (r == (BIGNUM *)0x0) {
              ERR_put_error(4,0x65,0x41,DAT_000fb618,0x21e);
              iVar3 = -1;
              goto LAB_000fb504;
            }
            CRYPTO_lock(9,0x19,DAT_000fb5b4,0x146);
            iVar3 = BN_BLINDING_convert_ex(ret,r,(BN_BLINDING *)pBVar2,ctx);
            CRYPTO_lock(10,0x19,DAT_000fb5b4,0x148);
          }
          else {
            iVar3 = BN_BLINDING_convert_ex(ret,(BIGNUM *)0x0,(BN_BLINDING *)pBVar2,ctx);
            r = (BIGNUM *)0x0;
          }
          if (iVar3 == 0) goto LAB_000fb44a;
          uVar6 = *(uint *)(param_4 + 0x3c);
        }
        if (((int)(uVar6 << 0x1a) < 0) ||
           ((((*(int *)(param_4 + 0x1c) != 0 && (*(int *)(param_4 + 0x20) != 0)) &&
             (*(int *)(param_4 + 0x24) != 0)) &&
            ((*(int *)(param_4 + 0x28) != 0 && (*(int *)(param_4 + 0x2c) != 0)))))) {
          iVar3 = (**(code **)(*(int *)(param_4 + 8) + 0x14))(n,ret,param_4,ctx);
        }
        else {
          if ((int)(uVar6 << 0x17) < 0) {
            puVar7 = *(undefined4 **)(param_4 + 0x18);
          }
          else {
            puVar5 = *(undefined4 **)(param_4 + 0x18);
            puVar7 = &local_3c;
            local_3c = *puVar5;
            local_38 = puVar5[1];
            local_34 = puVar5[2];
            local_30 = puVar5[3];
            local_2c = local_2c & 1 | puVar5[4] & 0xfffffffe | 6;
          }
          if (((int)(uVar6 << 0x1e) < 0) &&
             (pBVar4 = BN_MONT_CTX_set_locked
                                 ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),
                                  ctx), pBVar4 == (BN_MONT_CTX *)0x0)) goto LAB_000fb44a;
          iVar3 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                            (n,ret,puVar7,*(undefined4 *)(param_4 + 0x10),ctx,
                             *(undefined4 *)(param_4 + 0x40));
        }
        if ((iVar3 == 0) ||
           ((pBVar2 != (BIGNUM *)0x0 &&
            (iVar3 = BN_BLINDING_invert_ex(n,r,(BN_BLINDING *)pBVar2,ctx), iVar3 == 0))))
        goto LAB_000fb44a;
        iVar3 = BN_bn2bin(n,to);
        switch(param_5) {
        case 1:
          iVar3 = RSA_padding_check_PKCS1_type_2(param_3,len,to,iVar3,len);
          break;
        case 2:
          iVar3 = RSA_padding_check_SSLv23(param_3,len,to,iVar3,len);
          break;
        case 3:
          iVar3 = RSA_padding_check_none(param_3,len,to,iVar3,len);
          break;
        case 4:
          iVar3 = RSA_padding_check_PKCS1_OAEP(param_3,len,to,iVar3,len,(uchar *)0x0,0);
          break;
        default:
          iVar3 = -1;
          ERR_put_error(4,0x65,0x76,DAT_000fb5b4,0x256);
          goto LAB_000fb504;
        }
        if (iVar3 < 0) {
          ERR_put_error(4,0x65,0x72,DAT_000fb5b4,0x25a);
        }
      }
      else {
        ERR_put_error(4,0x65,0x84,DAT_000fb5b4,0x210);
        iVar3 = -1;
      }
    }
  }
LAB_000fb504:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_000fb510:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return iVar3;
}

