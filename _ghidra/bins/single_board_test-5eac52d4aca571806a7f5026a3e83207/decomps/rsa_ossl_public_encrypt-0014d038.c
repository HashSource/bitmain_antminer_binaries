
undefined4
rsa_ossl_public_encrypt
          (int param_1,uchar *param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *pBVar2;
  int iVar3;
  uchar *to;
  BIGNUM *pBVar4;
  BN_MONT_CTX *pBVar5;
  undefined4 uVar6;
  
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (0x4000 < iVar1) {
    ERR_put_error(4,0x68,0x69,"crypto/rsa/rsa_ossl.c",0x4d);
    return 0xffffffff;
  }
  iVar1 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar1 < 1) {
    iVar1 = 0x52;
  }
  else {
    iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
    if ((iVar1 < 0xc01) || (iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), iVar1 < 0x41)) {
      ctx = BN_CTX_new();
      if (ctx == (BN_CTX *)0x0) {
        uVar6 = 0xffffffff;
        iVar1 = 0;
        to = (uchar *)0x0;
      }
      else {
        BN_CTX_start(ctx);
        ret = BN_CTX_get(ctx);
        pBVar2 = BN_CTX_get(ctx);
        iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
        iVar1 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar1 = iVar3 + 0xe;
        }
        iVar1 = iVar1 >> 3;
        to = (uchar *)CRYPTO_malloc(iVar1,"crypto/rsa/rsa_ossl.c",100);
        if (to == (uchar *)0x0 || pBVar2 == (BIGNUM *)0x0) {
          uVar6 = 0xffffffff;
          ERR_put_error(4,0x68,0x41,"crypto/rsa/rsa_ossl.c",0x66);
        }
        else {
          switch(param_5) {
          case 1:
            iVar3 = RSA_padding_add_PKCS1_type_2(to,iVar1,param_2,param_1);
            break;
          case 2:
            iVar3 = RSA_padding_add_SSLv23(to,iVar1,param_2,param_1);
            break;
          case 3:
            iVar3 = RSA_padding_add_none(to,iVar1,param_2,param_1);
            break;
          case 4:
            iVar3 = RSA_padding_add_PKCS1_OAEP(to,iVar1,param_2,param_1,(uchar *)0x0,0);
            break;
          default:
            uVar6 = 0xffffffff;
            ERR_put_error(4,0x68,0x76,"crypto/rsa/rsa_ossl.c",0x78);
            goto LAB_0014d0fc;
          }
          if ((0 < iVar3) && (pBVar4 = BN_bin2bn(to,iVar1,ret), pBVar4 != (BIGNUM *)0x0)) {
            iVar3 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
            if (-1 < iVar3) {
              uVar6 = 0xffffffff;
              ERR_put_error(4,0x68,0x84,"crypto/rsa/rsa_ossl.c",0x84);
              goto LAB_0014d0fc;
            }
            if (((-1 < *(int *)(param_4 + 0x40) << 0x1e) ||
                (pBVar5 = BN_MONT_CTX_set_locked
                                    ((BN_MONT_CTX **)(param_4 + 0x44),*(int *)(param_4 + 0x5c),
                                     *(BIGNUM **)(param_4 + 0x10),ctx), pBVar5 != (BN_MONT_CTX *)0x0
                )) && (iVar3 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                                         (pBVar2,ret,*(undefined4 *)(param_4 + 0x14),
                                          *(undefined4 *)(param_4 + 0x10),ctx,
                                          *(undefined4 *)(param_4 + 0x44)), iVar3 != 0)) {
              uVar6 = BN_bn2binpad(pBVar2,param_3,iVar1);
              goto LAB_0014d0fc;
            }
          }
          uVar6 = 0xffffffff;
        }
      }
LAB_0014d0fc:
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      CRYPTO_clear_free(to,iVar1,"crypto/rsa/rsa_ossl.c",0x99);
      return uVar6;
    }
    iVar1 = 0x59;
  }
  ERR_put_error(4,0x68,0x65,"crypto/rsa/rsa_ossl.c",iVar1);
  return 0xffffffff;
}

