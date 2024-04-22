
int BN_is_prime_fasttest_ex_constprop_1(BIGNUM *param_1,BN_CTX *param_2,int *param_3)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *rnd;
  BIGNUM *pBVar3;
  int iVar4;
  BN_MONT_CTX *mont;
  BN_CTX *ctx;
  
  pBVar1 = BN_value_one();
  iVar2 = BN_cmp(param_1,pBVar1);
  if ((iVar2 < 1) || (param_1->top < 1)) {
    return 0;
  }
  if ((*param_1->d & 1) == 0) {
    if ((param_1->top == 1) && (*param_1->d == 2)) {
      if ((uint)param_1->neg < 2) {
        return 1 - param_1->neg;
      }
      return 0;
    }
    return 0;
  }
  ctx = param_2;
  if ((param_2 == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    return -1;
  }
  BN_CTX_start(ctx);
  pBVar1 = param_1;
  if (param_1->neg == 0) {
LAB_000f32c8:
    a = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    rnd = BN_CTX_get(ctx);
    if (((rnd != (BIGNUM *)0x0) && (pBVar3 = BN_copy(a,pBVar1), pBVar3 != (BIGNUM *)0x0)) &&
       (iVar2 = BN_sub_word(a,1), iVar2 != 0)) {
      if (a->top == 0) {
        iVar2 = 0;
        mont = (BN_MONT_CTX *)0x0;
        goto LAB_000f3398;
      }
      iVar2 = 1;
      while (iVar4 = BN_is_bit_set(a,iVar2), iVar4 == 0) {
        iVar2 = iVar2 + 1;
      }
      iVar4 = BN_rshift(r,a,iVar2);
      if ((iVar4 != 0) && (mont = BN_MONT_CTX_new(), mont != (BN_MONT_CTX *)0x0)) {
        iVar4 = BN_MONT_CTX_set(mont,pBVar1,ctx);
        if ((iVar4 == 0) ||
           ((iVar4 = BN_pseudo_rand_range(rnd,a), iVar4 == 0 ||
            (iVar4 = BN_add_word(rnd,1), iVar4 == 0)))) {
LAB_000f337c:
          iVar2 = -1;
        }
        else {
          iVar2 = witness(rnd,pBVar1,a,r,iVar2,ctx,mont);
          if (iVar2 == -1) {
            iVar2 = -1;
            goto LAB_000f3398;
          }
          if (iVar2 != 0) {
            iVar2 = 0;
            goto LAB_000f3398;
          }
          if (param_3 != (int *)0x0) {
            if (*param_3 == 1) {
              if ((code *)param_3[2] != (code *)0x0) {
                (*(code *)param_3[2])(1,0,param_3[1]);
              }
            }
            else if ((*param_3 != 2) || (iVar2 = (*(code *)param_3[2])(1,0,param_3), iVar2 == 0))
            goto LAB_000f337c;
          }
          iVar2 = 1;
        }
        goto LAB_000f3398;
      }
    }
  }
  else {
    pBVar1 = BN_CTX_get(ctx);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_copy(pBVar1,param_1);
      pBVar1->neg = 0;
      goto LAB_000f32c8;
    }
  }
  mont = (BN_MONT_CTX *)0x0;
  iVar2 = -1;
LAB_000f3398:
  BN_CTX_end(ctx);
  if (param_2 == (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(mont);
  }
  return iVar2;
}

