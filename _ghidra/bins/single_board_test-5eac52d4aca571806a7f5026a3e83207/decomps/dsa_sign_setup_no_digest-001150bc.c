
undefined4
dsa_sign_setup_no_digest(int param_1,BN_CTX *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *r;
  int iVar2;
  int iVar3;
  BN_MONT_CTX *pBVar4;
  BIGNUM *r_00;
  undefined4 uVar5;
  BIGNUM *pBVar6;
  BN_CTX *ctx;
  code *pcVar7;
  BIGNUM *a_00;
  
  if (((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
     (*(int *)(param_1 + 0x10) == 0)) {
    ERR_put_error(10,0x6b,0x65,"crypto/dsa/dsa_ossl.c",0xc1);
    return 0;
  }
  pBVar6 = (BIGNUM *)*param_4;
  iVar1 = BN_is_zero();
  if (((iVar1 != 0) || (iVar1 = BN_is_zero(*(undefined4 *)(param_1 + 0xc)), iVar1 != 0)) ||
     (iVar1 = BN_is_zero(*(undefined4 *)(param_1 + 0x10)), iVar1 != 0)) {
    ERR_put_error(10,0x6b,0x70,"crypto/dsa/dsa_ossl.c",199);
    return 0;
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    ERR_put_error(10,0x6b,0x6f,"crypto/dsa/dsa_ossl.c",0xcb);
    return 0;
  }
  a = BN_new();
  r = BN_new();
  if ((r == (BIGNUM *)0x0 || a == (BIGNUM *)0x0) ||
     ((ctx = param_2, param_2 == (BN_CTX *)0x0 && (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)))) {
    ctx = (BN_CTX *)0x0;
  }
  else {
    iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0xc));
    iVar2 = bn_get_top(*(undefined4 *)(param_1 + 0xc));
    iVar2 = iVar2 + 2;
    iVar3 = bn_wexpand(a,iVar2);
    if ((iVar3 != 0) && (iVar3 = bn_wexpand(r,iVar2), iVar3 != 0)) {
      do {
        iVar3 = BN_priv_rand_range(a,*(undefined4 *)(param_1 + 0xc));
        if (iVar3 == 0) goto LAB_0011514a;
        iVar3 = BN_is_zero(a);
      } while (iVar3 != 0);
      BN_set_flags(a,4);
      BN_set_flags(r,4);
      if ((((-1 < *(int *)(param_1 + 0x1c) << 0x1f) ||
           (pBVar4 = BN_MONT_CTX_set_locked
                               ((BN_MONT_CTX **)(param_1 + 0x20),*(int *)(param_1 + 0x34),
                                *(BIGNUM **)(param_1 + 8),ctx), pBVar4 != (BN_MONT_CTX *)0x0)) &&
          (iVar3 = BN_add(r,a,*(BIGNUM **)(param_1 + 0xc)), iVar3 != 0)) &&
         (iVar3 = BN_add(a,r,*(BIGNUM **)(param_1 + 0xc)), iVar3 != 0)) {
        iVar1 = BN_is_bit_set(r,iVar1);
        BN_consttime_swap(iVar1,a,r,iVar2);
        pcVar7 = *(code **)(*(int *)(param_1 + 0x2c) + 0x14);
        if (pcVar7 == (code *)0x0) {
          iVar1 = BN_mod_exp_mont(pBVar6,*(BIGNUM **)(param_1 + 0x10),a,*(BIGNUM **)(param_1 + 8),
                                  ctx,*(BN_MONT_CTX **)(param_1 + 0x20));
        }
        else {
          iVar1 = (*pcVar7)(param_1,pBVar6,*(undefined4 *)(param_1 + 0x10),a,
                            *(undefined4 *)(param_1 + 8),ctx,*(undefined4 *)(param_1 + 0x20));
        }
        if ((iVar1 != 0) &&
           (iVar1 = BN_div((BIGNUM *)0x0,pBVar6,pBVar6,*(BIGNUM **)(param_1 + 0xc),ctx), iVar1 != 0)
           ) {
          a_00 = *(BIGNUM **)(param_1 + 0xc);
          pBVar6 = BN_new();
          if (pBVar6 != (BIGNUM *)0x0) {
            BN_CTX_start(ctx);
            r_00 = BN_CTX_get(ctx);
            if (((r_00 != (BIGNUM *)0x0) && (iVar1 = BN_set_word(pBVar6,2), iVar1 != 0)) &&
               ((iVar1 = BN_sub(r_00,a_00,pBVar6), iVar1 != 0 &&
                (iVar1 = BN_mod_exp_mont(pBVar6,a,r_00,a_00,ctx,(BN_MONT_CTX *)0x0), iVar1 != 0))))
            {
              uVar5 = 1;
              BN_CTX_end(ctx);
              BN_clear_free((BIGNUM *)*param_3);
              *param_3 = pBVar6;
              goto LAB_00115160;
            }
            BN_free(pBVar6);
            BN_CTX_end(ctx);
          }
        }
      }
    }
  }
LAB_0011514a:
  uVar5 = 0;
  ERR_put_error(10,0x6b,3,"crypto/dsa/dsa_ossl.c",0x123);
LAB_00115160:
  if (param_2 != ctx) {
    BN_CTX_free(ctx);
  }
  BN_clear_free(a);
  BN_clear_free(r);
  return uVar5;
}

