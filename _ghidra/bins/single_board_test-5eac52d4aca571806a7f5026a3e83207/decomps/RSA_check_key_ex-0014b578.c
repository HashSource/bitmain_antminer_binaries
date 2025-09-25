
uint RSA_check_key_ex(int param_1,BN_GENCB *param_2)

{
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *r_02;
  BIGNUM *r_03;
  BN_CTX *ctx;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *pBVar6;
  uint uVar7;
  int iVar8;
  
  if ((((*(int *)(param_1 + 0x1c) == 0) || (*(int *)(param_1 + 0x20) == 0)) ||
      (*(int *)(param_1 + 0x10) == 0)) ||
     ((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x18) == 0)))) {
    ERR_put_error(4,0xa0,0x93,"crypto/rsa/rsa_chk.c",0x1c);
    return 0;
  }
  if (*(int *)(param_1 + 4) == 1) {
    iVar8 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x30));
    if (iVar8 < 1) {
LAB_0014b74a:
      ERR_put_error(4,0xa0,0xa7,"crypto/rsa/rsa_chk.c",0x25);
      return 0;
    }
    BN_num_bits(*(BIGNUM **)(param_1 + 0x10));
    iVar1 = rsa_multip_cap();
    if (iVar1 <= iVar8 + 1) goto LAB_0014b74a;
  }
  else {
    iVar8 = 0;
  }
  r = BN_new();
  r_00 = BN_new();
  r_01 = BN_new();
  r_02 = BN_new();
  r_03 = BN_new();
  ctx = BN_CTX_new();
  if (((r_00 == (BIGNUM *)0x0 || r == (BIGNUM *)0x0) ||
      (r_02 == (BIGNUM *)0x0 || r_01 == (BIGNUM *)0x0)) ||
     (ctx == (BN_CTX *)0x0 || r_03 == (BIGNUM *)0x0)) {
    uVar7 = 0xffffffff;
    ERR_put_error(4,0xa0,0x41,"crypto/rsa/rsa_chk.c",0x33);
    goto LAB_0014b602;
  }
  iVar1 = BN_is_one(*(undefined4 *)(param_1 + 0x14));
  if (iVar1 != 0) {
    ERR_put_error(4,0xa0,0x65,"crypto/rsa/rsa_chk.c",0x39);
  }
  uVar7 = (uint)(iVar1 == 0);
  iVar1 = BN_is_odd(*(undefined4 *)(param_1 + 0x14));
  if (iVar1 == 0) {
    ERR_put_error(4,0xa0,0x65,"crypto/rsa/rsa_chk.c",0x3d);
    uVar7 = 0;
  }
  iVar1 = BN_is_prime_ex(*(BIGNUM **)(param_1 + 0x1c),0,(BN_CTX *)0x0,param_2);
  if (iVar1 != 1) {
    uVar7 = 0;
    ERR_put_error(4,0xa0,0x80,"crypto/rsa/rsa_chk.c",0x43);
  }
  iVar1 = BN_is_prime_ex(*(BIGNUM **)(param_1 + 0x20),0,(BN_CTX *)0x0,param_2);
  if (iVar1 != 1) {
    uVar7 = 0;
    ERR_put_error(4,0xa0,0x81,"crypto/rsa/rsa_chk.c",0x49);
  }
  if (iVar8 == 0) {
    iVar1 = BN_mul(r,*(BIGNUM **)(param_1 + 0x1c),*(BIGNUM **)(param_1 + 0x20),ctx);
    if (iVar1 != 0) {
      iVar1 = BN_cmp(r,*(BIGNUM **)(param_1 + 0x10));
      if (iVar1 != 0) {
        ERR_put_error(4,0xa0,0x7f,"crypto/rsa/rsa_chk.c",0x67);
        uVar7 = 0;
      }
      goto LAB_0014b7b8;
    }
  }
  else {
    iVar1 = 0;
    do {
      puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar1);
      iVar3 = BN_is_prime_ex((BIGNUM *)*puVar2,0,(BN_CTX *)0x0,param_2);
      iVar1 = iVar1 + 1;
      if (iVar3 != 1) {
        uVar7 = 0;
        ERR_put_error(4,0xa0,0xaa,"crypto/rsa/rsa_chk.c",0x51);
      }
    } while (iVar1 != iVar8);
    iVar3 = 0;
    iVar1 = BN_mul(r,*(BIGNUM **)(param_1 + 0x1c),*(BIGNUM **)(param_1 + 0x20),ctx);
    if (iVar1 != 0) {
      do {
        puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar3);
        iVar3 = iVar3 + 1;
        iVar1 = BN_mul(r,r,(BIGNUM *)*puVar2,ctx);
        if (iVar1 == 0) goto LAB_0014b724;
      } while (iVar8 != iVar3);
      iVar1 = BN_cmp(r,*(BIGNUM **)(param_1 + 0x10));
      if (iVar1 != 0) {
        uVar7 = 0;
        ERR_put_error(4,0xa0,0xac,"crypto/rsa/rsa_chk.c",0x65);
      }
LAB_0014b7b8:
      pBVar6 = *(BIGNUM **)(param_1 + 0x1c);
      pBVar4 = BN_value_one();
      iVar1 = BN_sub(r,pBVar6,pBVar4);
      if (iVar1 != 0) {
        pBVar6 = *(BIGNUM **)(param_1 + 0x20);
        pBVar4 = BN_value_one();
        iVar1 = BN_sub(r_00,pBVar6,pBVar4);
        if (((iVar1 != 0) && (iVar1 = BN_mul(r_02,r,r_00,ctx), iVar1 != 0)) &&
           (iVar1 = BN_gcd(r_03,r,r_00,ctx), iVar1 != 0)) {
          iVar1 = 0;
          if (iVar8 != 0) {
            do {
              puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar1);
              pBVar6 = (BIGNUM *)*puVar2;
              iVar1 = iVar1 + 1;
              pBVar4 = BN_value_one();
              iVar3 = BN_sub(r_01,pBVar6,pBVar4);
              if (((iVar3 == 0) || (iVar3 = BN_mul(r_02,r_02,r_01,ctx), iVar3 == 0)) ||
                 (iVar3 = BN_gcd(r_03,r_03,r_01,ctx), iVar3 == 0)) goto LAB_0014b724;
            } while (iVar8 != iVar1);
          }
          iVar1 = BN_div(r_01,(BIGNUM *)0x0,r_02,r_03,ctx);
          if ((iVar1 != 0) &&
             (iVar1 = BN_mod_mul(r,*(BIGNUM **)(param_1 + 0x18),*(BIGNUM **)(param_1 + 0x14),r_01,
                                 ctx), iVar1 != 0)) {
            iVar1 = BN_is_one(r);
            if (iVar1 == 0) {
              ERR_put_error(4,0xa0,0x7b,"crypto/rsa/rsa_chk.c",0x97);
              uVar7 = 0;
            }
            if (((*(int *)(param_1 + 0x24) == 0) || (*(int *)(param_1 + 0x28) == 0)) ||
               (*(int *)(param_1 + 0x2c) == 0)) {
LAB_0014b9be:
              iVar1 = 0;
              while (iVar3 = iVar1 + 1, iVar8 != iVar1) {
                puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar1);
                pBVar6 = (BIGNUM *)*puVar2;
                pBVar4 = BN_value_one();
                iVar1 = BN_sub(r,pBVar6,pBVar4);
                if ((iVar1 == 0) ||
                   (iVar1 = BN_div((BIGNUM *)0x0,r_00,*(BIGNUM **)(param_1 + 0x18),r,ctx),
                   iVar1 == 0)) goto LAB_0014b724;
                iVar1 = BN_cmp(r_00,(BIGNUM *)puVar2[1]);
                if (iVar1 != 0) {
                  uVar7 = 0;
                  ERR_put_error(4,0xa0,0xa9,"crypto/rsa/rsa_chk.c",0xcf);
                }
                pBVar4 = BN_mod_inverse(r,(BIGNUM *)puVar2[3],(BIGNUM *)*puVar2,ctx);
                if (pBVar4 == (BIGNUM *)0x0) goto LAB_0014b724;
                iVar5 = BN_cmp(r,(BIGNUM *)puVar2[2]);
                iVar1 = iVar3;
                if (iVar5 != 0) {
                  uVar7 = 0;
                  ERR_put_error(4,0xa0,0xa8,"crypto/rsa/rsa_chk.c",0xd8);
                }
              }
              goto LAB_0014b602;
            }
            pBVar6 = *(BIGNUM **)(param_1 + 0x1c);
            pBVar4 = BN_value_one();
            iVar1 = BN_sub(r,pBVar6,pBVar4);
            if ((iVar1 != 0) &&
               (iVar1 = BN_div((BIGNUM *)0x0,r_00,*(BIGNUM **)(param_1 + 0x18),r,ctx), iVar1 != 0))
            {
              iVar1 = BN_cmp(r_00,*(BIGNUM **)(param_1 + 0x24));
              if (iVar1 != 0) {
                uVar7 = 0;
                ERR_put_error(4,0xa0,0x7c,"crypto/rsa/rsa_chk.c",0xa6);
              }
              pBVar6 = *(BIGNUM **)(param_1 + 0x20);
              pBVar4 = BN_value_one();
              iVar1 = BN_sub(r,pBVar6,pBVar4);
              if ((iVar1 != 0) &&
                 (iVar1 = BN_div((BIGNUM *)0x0,r_00,*(BIGNUM **)(param_1 + 0x18),r,ctx), iVar1 != 0)
                 ) {
                iVar1 = BN_cmp(r_00,*(BIGNUM **)(param_1 + 0x28));
                if (iVar1 != 0) {
                  uVar7 = 0;
                  ERR_put_error(4,0xa0,0x7d,"crypto/rsa/rsa_chk.c",0xb4);
                }
                pBVar4 = BN_mod_inverse(r,*(BIGNUM **)(param_1 + 0x20),*(BIGNUM **)(param_1 + 0x1c),
                                        ctx);
                if (pBVar4 != (BIGNUM *)0x0) {
                  iVar1 = BN_cmp(r,*(BIGNUM **)(param_1 + 0x2c));
                  if (iVar1 != 0) {
                    uVar7 = 0;
                    ERR_put_error(4,0xa0,0x7e,"crypto/rsa/rsa_chk.c",0xbe);
                  }
                  goto LAB_0014b9be;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0014b724:
  uVar7 = 0xffffffff;
LAB_0014b602:
  BN_free(r);
  BN_free(r_00);
  BN_free(r_01);
  BN_free(r_02);
  BN_free(r_03);
  BN_CTX_free(ctx);
  return uVar7;
}

