
BIGNUM * ec_GFp_simple_add(EC_GROUP *param_1,EC_POINT *param_2,EC_POINT *param_3,EC_POINT *param_4,
                          BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *a_03;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  EC_POINT *src;
  BIGNUM *pBVar3;
  code *pcVar4;
  code *pcVar5;
  BN_CTX *c;
  
  if (param_3 == param_4) {
    pBVar3 = (BIGNUM *)EC_POINT_dbl(param_1,param_2,param_3,param_5);
    return pBVar3;
  }
  iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
  src = param_4;
  if ((iVar1 != 0) || (iVar1 = EC_POINT_is_at_infinity(param_1,param_4), src = param_3, iVar1 != 0))
  {
    pBVar3 = (BIGNUM *)EC_POINT_copy(param_2,src);
    return pBVar3;
  }
  pBVar3 = *(BIGNUM **)(param_1 + 0x28);
  pcVar4 = *(code **)(*(int *)param_1 + 0x88);
  pcVar5 = *(code **)(*(int *)param_1 + 0x8c);
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return (BIGNUM *)0x0;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  a_02 = BN_CTX_get(param_5);
  a_03 = BN_CTX_get(param_5);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  pBVar2 = r_00;
  if (r_00 == (BIGNUM *)0x0) goto LAB_0012d9fc;
  if (*(int *)(param_4 + 0x14) == 0) {
    pBVar2 = (BIGNUM *)(*pcVar5)(param_1,a,*(undefined4 *)(param_4 + 0x10),param_5);
    if (((pBVar2 == (BIGNUM *)0x0) ||
        (pBVar2 = (BIGNUM *)(*pcVar4)(param_1,a_00,*(undefined4 *)(param_3 + 8),a,param_5),
        pBVar2 == (BIGNUM *)0x0)) ||
       (pBVar2 = (BIGNUM *)(*pcVar4)(param_1,a,a,*(undefined4 *)(param_4 + 0x10),param_5),
       pBVar2 == (BIGNUM *)0x0)) goto LAB_0012d9fc;
    iVar1 = (*pcVar4)(param_1,a_01,*(undefined4 *)(param_3 + 0xc),a,param_5);
    if (iVar1 == 0) {
      pBVar2 = (BIGNUM *)0x0;
      goto LAB_0012d9fc;
    }
  }
  else {
    pBVar2 = BN_copy(a_00,*(BIGNUM **)(param_3 + 8));
    if ((pBVar2 == (BIGNUM *)0x0) ||
       (pBVar2 = BN_copy(a_01,*(BIGNUM **)(param_3 + 0xc)), pBVar2 == (BIGNUM *)0x0))
    goto LAB_0012d9fc;
  }
  if (*(int *)(param_3 + 0x14) == 0) {
    pBVar2 = (BIGNUM *)(*pcVar5)(param_1,a,*(undefined4 *)(param_3 + 0x10),param_5);
    if (((pBVar2 == (BIGNUM *)0x0) ||
        (pBVar2 = (BIGNUM *)(*pcVar4)(param_1,a_02,*(undefined4 *)(param_4 + 8),a,param_5),
        pBVar2 == (BIGNUM *)0x0)) ||
       (pBVar2 = (BIGNUM *)(*pcVar4)(param_1,a,a,*(undefined4 *)(param_3 + 0x10),param_5),
       pBVar2 == (BIGNUM *)0x0)) goto LAB_0012d9fc;
    iVar1 = (*pcVar4)(param_1,a_03,*(undefined4 *)(param_4 + 0xc),a,param_5);
    if (iVar1 == 0) {
      pBVar2 = (BIGNUM *)0x0;
      goto LAB_0012d9fc;
    }
  }
  else {
    pBVar2 = BN_copy(a_02,*(BIGNUM **)(param_4 + 8));
    if ((pBVar2 == (BIGNUM *)0x0) ||
       (pBVar2 = BN_copy(a_03,*(BIGNUM **)(param_4 + 0xc)), pBVar2 == (BIGNUM *)0x0))
    goto LAB_0012d9fc;
  }
  pBVar2 = (BIGNUM *)BN_mod_sub_quick(r,a_00,a_02,pBVar3);
  if ((pBVar2 == (BIGNUM *)0x0) ||
     (pBVar2 = (BIGNUM *)BN_mod_sub_quick(r_00,a_01,a_03,pBVar3), pBVar2 == (BIGNUM *)0x0))
  goto LAB_0012d9fc;
  iVar1 = BN_is_zero(r);
  if (iVar1 != 0) {
    iVar1 = BN_is_zero(r_00);
    if (iVar1 == 0) {
      BN_set_word(*(BIGNUM **)(param_2 + 0x10),0);
      pBVar2 = (BIGNUM *)0x1;
      *(undefined4 *)(param_2 + 0x14) = 0;
    }
    else {
      BN_CTX_end(param_5);
      pBVar2 = (BIGNUM *)EC_POINT_dbl(param_1,param_2,param_3,param_5);
      param_5 = (BN_CTX *)0x0;
    }
    goto LAB_0012d9fc;
  }
  pBVar2 = (BIGNUM *)BN_mod_add_quick(a_00,a_00,a_02,pBVar3);
  if ((pBVar2 == (BIGNUM *)0x0) ||
     (pBVar2 = (BIGNUM *)BN_mod_add_quick(a_01,a_01,a_03,pBVar3), pBVar2 == (BIGNUM *)0x0))
  goto LAB_0012d9fc;
  if (*(int *)(param_3 + 0x14) == 0) {
    if (*(int *)(param_4 + 0x14) == 0) {
      iVar1 = (*pcVar4)(param_1,a,*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_4 + 0x10),
                        param_5);
      if (iVar1 == 0) {
        pBVar2 = (BIGNUM *)0x0;
        goto LAB_0012d9fc;
      }
    }
    else {
      pBVar2 = BN_copy(a,*(BIGNUM **)(param_3 + 0x10));
      if (pBVar2 == (BIGNUM *)0x0) {
        pBVar2 = (BIGNUM *)0x0;
        goto LAB_0012d9fc;
      }
    }
LAB_0012db16:
    pBVar2 = (BIGNUM *)(*pcVar4)(param_1,*(undefined4 *)(param_2 + 0x10),a,r,param_5);
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_0012d9fc;
  }
  else {
    if (*(int *)(param_4 + 0x14) == 0) {
      pBVar2 = BN_copy(a,*(BIGNUM **)(param_4 + 0x10));
      if (pBVar2 == (BIGNUM *)0x0) goto LAB_0012d9fc;
      goto LAB_0012db16;
    }
    pBVar2 = BN_copy(*(BIGNUM **)(param_2 + 0x10),r);
    if (pBVar2 == (BIGNUM *)0x0) {
      pBVar2 = (BIGNUM *)0x0;
      goto LAB_0012d9fc;
    }
  }
  *(undefined4 *)(param_2 + 0x14) = 0;
  pBVar2 = (BIGNUM *)(*pcVar5)(param_1,a,r_00,param_5);
  if ((((((pBVar2 != (BIGNUM *)0x0) &&
         (pBVar2 = (BIGNUM *)(*pcVar5)(param_1,a_03,r,param_5), pBVar2 != (BIGNUM *)0x0)) &&
        (pBVar2 = (BIGNUM *)(*pcVar4)(param_1,a_02,a_00,a_03,param_5), pBVar2 != (BIGNUM *)0x0)) &&
       ((pBVar2 = (BIGNUM *)BN_mod_sub_quick(*(BIGNUM **)(param_2 + 8),a,a_02,pBVar3),
        pBVar2 != (BIGNUM *)0x0 &&
        (pBVar2 = (BIGNUM *)BN_mod_lshift1_quick(a,*(BIGNUM **)(param_2 + 8),pBVar3),
        pBVar2 != (BIGNUM *)0x0)))) &&
      ((pBVar2 = (BIGNUM *)BN_mod_sub_quick(a,a_02,a,pBVar3), pBVar2 != (BIGNUM *)0x0 &&
       ((pBVar2 = (BIGNUM *)(*pcVar4)(param_1,a,a,r_00,param_5), pBVar2 != (BIGNUM *)0x0 &&
        (pBVar2 = (BIGNUM *)(*pcVar4)(param_1,r,a_03,r,param_5), pBVar2 != (BIGNUM *)0x0)))))) &&
     (pBVar2 = (BIGNUM *)(*pcVar4)(param_1,a_00,a_01,r,param_5), pBVar2 != (BIGNUM *)0x0)) {
    iVar1 = BN_mod_sub_quick(a,a,a_00,pBVar3);
    if (iVar1 == 0) {
      pBVar2 = (BIGNUM *)0x0;
    }
    else {
      iVar1 = BN_is_odd(a);
      if ((iVar1 == 0) || (iVar1 = BN_add(a,a,pBVar3), iVar1 != 0)) {
        pBVar2 = (BIGNUM *)BN_rshift1(*(BIGNUM **)(param_2 + 0xc),a);
        if (pBVar2 != (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)0x1;
        }
      }
      else {
        pBVar2 = (BIGNUM *)0x0;
      }
    }
  }
LAB_0012d9fc:
  BN_CTX_end(param_5);
  BN_CTX_free(c);
  return pBVar2;
}

