
uint ecdh_compute_key(void *param_1,uint param_2,EC_POINT *param_3,EC_KEY *param_4,code *param_5)

{
  BN_CTX *ctx;
  BIGNUM *cofactor;
  BIGNUM *y;
  BIGNUM *b;
  EC_GROUP *group;
  int iVar1;
  EC_POINT *r;
  void *__s;
  EC_METHOD *meth;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_2c [2];
  
  local_2c[0] = param_2;
  if ((int)param_2 < 0) {
    ERR_put_error(0x2b,100,0x41,DAT_00101260,0x7b);
    return 0xffffffff;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0xffffffff;
  }
  BN_CTX_start(ctx);
  cofactor = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  b = EC_KEY_get0_private_key(param_4);
  if (b == (BIGNUM *)0x0) {
    ERR_put_error(0x2b,100,100,DAT_00101260,0x88);
  }
  else {
    group = EC_KEY_get0_group(param_4);
    iVar1 = EC_KEY_get_flags(param_4);
    if ((iVar1 << 0x13 < 0) &&
       ((iVar1 = EC_GROUP_get_cofactor(group,cofactor,ctx), iVar1 == 0 ||
        (iVar1 = BN_mul(cofactor,cofactor,b,ctx), b = cofactor, iVar1 == 0)))) {
      iVar1 = 0x91;
    }
    else {
      r = EC_POINT_new(group);
      if (r != (EC_POINT *)0x0) {
        __s = (void *)EC_POINT_mul(group,r,(BIGNUM *)0x0,param_3,b,ctx);
        iVar1 = 0x9d;
        if (__s == (void *)0x0) {
LAB_0010111e:
          uVar6 = 0xffffffff;
          ERR_put_error(0x2b,100,0x65,DAT_00101260,iVar1);
        }
        else {
          meth = EC_GROUP_method_of(group);
          iVar1 = EC_METHOD_get_field_type(meth);
          if (iVar1 == 0x196) {
            iVar2 = EC_POINT_get_affine_coordinates_GFp(group,r,cofactor,y,ctx);
            iVar1 = 0xa4;
            if (iVar2 == 0) {
              __s = (void *)0x0;
              goto LAB_0010111e;
            }
          }
          else {
            iVar1 = EC_POINT_get_affine_coordinates_GF2m();
            if (iVar1 == 0) {
              iVar1 = 0xab;
              __s = (void *)0x0;
              goto LAB_0010111e;
            }
          }
          iVar2 = EC_GROUP_get_degree(group);
          iVar1 = iVar2 + 0xe;
          if (-1 < iVar2 + 7) {
            iVar1 = iVar2 + 7;
          }
          iVar3 = BN_num_bits(cofactor);
          iVar2 = iVar3 + 0xe;
          if (-1 < iVar3 + 7) {
            iVar2 = iVar3 + 7;
          }
          uVar6 = iVar1 >> 3;
          uVar5 = iVar2 >> 3;
          if (uVar6 < uVar5) {
            ERR_put_error(0x2b,100,0x44,DAT_00101260,0xb4);
            __s = (void *)0x0;
            uVar6 = 0xffffffff;
          }
          else {
            __s = CRYPTO_malloc(uVar6,DAT_00101260,0xb7);
            if (__s == (void *)0x0) {
              ERR_put_error(0x2b,100,0x41,DAT_00101260,0xb8);
              uVar6 = 0xffffffff;
            }
            else {
              memset(__s,0,uVar6 - uVar5);
              uVar4 = BN_bn2bin(cofactor,(uchar *)((int)__s + (uVar6 - uVar5)));
              if (uVar4 == uVar5) {
                if (param_5 == (code *)0x0) {
                  if (uVar6 < local_2c[0]) {
                    local_2c[0] = uVar6;
                  }
                  uVar6 = local_2c[0];
                  memcpy(param_1,__s,local_2c[0]);
                }
                else {
                  iVar1 = (*param_5)(__s,uVar6,param_1,local_2c);
                  uVar6 = local_2c[0];
                  if (iVar1 == 0) {
                    ERR_put_error(0x2b,100,0x66,DAT_00101260,0xc4);
                    uVar6 = 0xffffffff;
                  }
                }
              }
              else {
                ERR_put_error(0x2b,100,3,DAT_00101260,0xbe);
                uVar6 = 0xffffffff;
              }
            }
          }
        }
        EC_POINT_free(r);
        goto LAB_00101136;
      }
      iVar1 = 0x98;
    }
    ERR_put_error(0x2b,100,0x41,DAT_00101260,iVar1);
  }
  uVar6 = 0xffffffff;
  __s = (void *)0x0;
LAB_00101136:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  if (__s != (void *)0x0) {
    CRYPTO_free(__s);
  }
  return uVar6;
}

