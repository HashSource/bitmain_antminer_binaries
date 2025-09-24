
undefined4
ecdh_simple_compute_key(undefined4 *param_1,uint *param_2,EC_POINT *param_3,EC_KEY *param_4)

{
  uint num;
  uint uVar1;
  BN_CTX *ctx;
  BIGNUM *cofactor;
  BIGNUM *b;
  EC_GROUP *group;
  int iVar2;
  EC_POINT *r;
  int iVar3;
  void *__s;
  uint uVar4;
  undefined4 uVar5;
  
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    __s = (void *)0x0;
    r = (EC_POINT *)0x0;
    uVar5 = 0;
  }
  else {
    BN_CTX_start(ctx);
    cofactor = BN_CTX_get(ctx);
    if (cofactor == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x101,0x41,"crypto/ec/ecdh_ossl.c",0x37);
      __s = (void *)0x0;
      r = (EC_POINT *)0x0;
      uVar5 = 0;
    }
    else {
      b = EC_KEY_get0_private_key(param_4);
      if (b == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x101,0x7d,"crypto/ec/ecdh_ossl.c",0x3d);
        __s = (void *)0x0;
        r = (EC_POINT *)0x0;
        uVar5 = 0;
      }
      else {
        group = EC_KEY_get0_group(param_4);
        iVar2 = EC_KEY_get_flags(param_4);
        if ((iVar2 << 0x13 < 0) &&
           ((iVar2 = EC_GROUP_get_cofactor(group,cofactor,(BN_CTX *)0x0), iVar2 == 0 ||
            (iVar2 = BN_mul(cofactor,cofactor,b,ctx), b = cofactor, iVar2 == 0)))) {
          __s = (void *)0x0;
          ERR_put_error(0x10,0x101,0x41,"crypto/ec/ecdh_ossl.c",0x46);
          uVar5 = 0;
          r = (EC_POINT *)0x0;
        }
        else {
          r = EC_POINT_new(group);
          if (r == (EC_POINT *)0x0) {
            ERR_put_error(0x10,0x101,0x41,"crypto/ec/ecdh_ossl.c",0x4d);
            __s = (void *)0x0;
            uVar5 = 0;
          }
          else {
            iVar2 = EC_POINT_mul(group,r,(BIGNUM *)0x0,param_3,b,ctx);
            if (iVar2 == 0) {
              ERR_put_error(0x10,0x101,0x9b,"crypto/ec/ecdh_ossl.c",0x52);
              __s = (void *)0x0;
              uVar5 = 0;
            }
            else {
              iVar2 = EC_POINT_get_affine_coordinates(group,r,cofactor,0,ctx);
              if (iVar2 == 0) {
                ERR_put_error(0x10,0x101,0x9b,"crypto/ec/ecdh_ossl.c",0x57);
                __s = (void *)0x0;
                uVar5 = 0;
              }
              else {
                iVar3 = EC_GROUP_get_degree(group);
                iVar2 = iVar3 + 7;
                if (iVar3 + 7 < 0) {
                  iVar2 = iVar3 + 0xe;
                }
                num = iVar2 >> 3;
                iVar3 = BN_num_bits(cofactor);
                iVar2 = iVar3 + 7;
                if (iVar3 + 7 < 0) {
                  iVar2 = iVar3 + 0xe;
                }
                uVar1 = iVar2 >> 3;
                if (num < uVar1) {
                  __s = (void *)0x0;
                  ERR_put_error(0x10,0x101,0x44,"crypto/ec/ecdh_ossl.c",0x5e);
                  uVar5 = 0;
                }
                else {
                  __s = CRYPTO_malloc(num,"crypto/ec/ecdh_ossl.c",0x61);
                  if (__s == (void *)0x0) {
                    ERR_put_error(0x10,0x101,0x41,"crypto/ec/ecdh_ossl.c",0x62);
                    uVar5 = 0;
                  }
                  else {
                    memset(__s,0,num - uVar1);
                    uVar4 = BN_bn2bin(cofactor,(uchar *)((int)__s + (num - uVar1)));
                    if (uVar1 == uVar4) {
                      *param_1 = __s;
                      uVar5 = 1;
                      *param_2 = num;
                      __s = (void *)0x0;
                    }
                    else {
                      ERR_put_error(0x10,0x101,3,"crypto/ec/ecdh_ossl.c",0x68);
                      uVar5 = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  EC_POINT_clear_free(r);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  CRYPTO_free(__s);
  return uVar5;
}

