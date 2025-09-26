
undefined4 dsa_sign_setup(int param_1,BN_CTX *param_2,undefined4 *param_3,undefined4 *param_4)

{
  BIGNUM *r;
  int iVar1;
  BIGNUM *pBVar2;
  BN_MONT_CTX *pBVar3;
  int iVar4;
  BN_CTX *ctx;
  uint uVar5;
  undefined4 uVar6;
  code *pcVar7;
  BIGNUM BStack_50;
  BIGNUM BStack_3c;
  
  if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (*(int *)(param_1 + 0x14) == 0)) {
    ERR_put_error(10,0x6b,0x65,"dsa_ossl.c",0xe6);
    return 0;
  }
  BN_init(&BStack_50);
  BN_init(&BStack_3c);
  ctx = param_2;
  if (((param_2 == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) ||
     (r = BN_new(), r == (BIGNUM *)0x0)) {
    ERR_put_error(10,0x6b,3,"dsa_ossl.c",0x130);
    uVar6 = 0;
    goto LAB_0019711c;
  }
  do {
    iVar1 = BN_rand_range(&BStack_50,*(BIGNUM **)(param_1 + 0x10));
    if (iVar1 == 0) goto LAB_00197102;
  } while (BStack_50.top == 0);
  uVar5 = *(uint *)(param_1 + 0x28) & 2;
  if (uVar5 == 0) {
    BStack_50.flags = BStack_50.flags | 4;
  }
  if ((int)(*(uint *)(param_1 + 0x28) << 0x1f) < 0) {
    pBVar3 = BN_MONT_CTX_set_locked
                       ((BN_MONT_CTX **)(param_1 + 0x2c),8,*(BIGNUM **)(param_1 + 0xc),ctx);
    if (pBVar3 == (BN_MONT_CTX *)0x0) goto LAB_00197102;
    pBVar2 = &BStack_50;
    if ((*(uint *)(param_1 + 0x28) & 2) == 0) goto LAB_001971ac;
LAB_001970da:
    pcVar7 = *(code **)(*(int *)(param_1 + 0x3c) + 0x14);
    if (pcVar7 == (code *)0x0) {
      iVar1 = BN_mod_exp_mont(r,*(BIGNUM **)(param_1 + 0x14),pBVar2,*(BIGNUM **)(param_1 + 0xc),ctx,
                              *(BN_MONT_CTX **)(param_1 + 0x2c));
    }
    else {
      iVar1 = (*pcVar7)(param_1,r,*(undefined4 *)(param_1 + 0x14),pBVar2,
                        *(undefined4 *)(param_1 + 0xc),ctx,*(undefined4 *)(param_1 + 0x2c));
    }
    if (((iVar1 != 0) &&
        (iVar1 = BN_div((BIGNUM *)0x0,r,r,*(BIGNUM **)(param_1 + 0x10),ctx), iVar1 != 0)) &&
       (pBVar2 = BN_mod_inverse((BIGNUM *)0x0,&BStack_50,*(BIGNUM **)(param_1 + 0x10),ctx),
       pBVar2 != (BIGNUM *)0x0)) {
      if ((BIGNUM *)*param_3 != (BIGNUM *)0x0) {
        BN_clear_free((BIGNUM *)*param_3);
      }
      *param_3 = pBVar2;
      if ((BIGNUM *)*param_4 != (BIGNUM *)0x0) {
        BN_clear_free((BIGNUM *)*param_4);
      }
      uVar6 = 1;
      *param_4 = r;
      goto LAB_0019711c;
    }
  }
  else {
    pBVar2 = &BStack_50;
    if (uVar5 != 0) goto LAB_001970da;
LAB_001971ac:
    pBVar2 = BN_copy(&BStack_3c,&BStack_50);
    if ((pBVar2 != (BIGNUM *)0x0) &&
       (iVar1 = BN_add(&BStack_3c,&BStack_3c,*(BIGNUM **)(param_1 + 0x10)), iVar1 != 0)) {
      iVar1 = BN_num_bits(&BStack_3c);
      iVar4 = BN_num_bits(*(BIGNUM **)(param_1 + 0x10));
      if ((iVar4 < iVar1) ||
         (iVar1 = BN_add(&BStack_3c,&BStack_3c,*(BIGNUM **)(param_1 + 0x10)), iVar1 != 0)) {
        pBVar2 = &BStack_3c;
        goto LAB_001970da;
      }
    }
  }
LAB_00197102:
  uVar6 = 0;
  ERR_put_error(10,0x6b,3,"dsa_ossl.c",0x130);
  BN_clear_free(r);
LAB_0019711c:
  if (param_2 == (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  BN_clear_free(&BStack_50);
  BN_clear_free(&BStack_3c);
  return uVar6;
}

