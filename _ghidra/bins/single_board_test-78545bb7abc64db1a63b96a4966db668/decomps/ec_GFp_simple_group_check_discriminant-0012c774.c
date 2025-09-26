
BIGNUM * ec_GFp_simple_group_check_discriminant(int *param_1,BN_CTX *param_2)

{
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *m;
  BN_CTX *c;
  
  m = (BIGNUM *)param_1[10];
  c = (BN_CTX *)0x0;
  if ((param_2 == (BN_CTX *)0x0) && (param_2 = BN_CTX_new(), c = param_2, param_2 == (BN_CTX *)0x0))
  {
    ERR_put_error(0x10,0xa5,0x41,"crypto/ec/ecp_smpl.c",0xfe);
    pBVar1 = (BIGNUM *)0x0;
  }
  else {
    BN_CTX_start(param_2);
    a = BN_CTX_get(param_2);
    a_00 = BN_CTX_get(param_2);
    r = BN_CTX_get(param_2);
    r_00 = BN_CTX_get(param_2);
    pBVar1 = BN_CTX_get(param_2);
    if (pBVar1 != (BIGNUM *)0x0) {
      if (*(code **)(*param_1 + 0x9c) == (code *)0x0) {
        pBVar1 = BN_copy(a,(BIGNUM *)param_1[0x11]);
        if (pBVar1 == (BIGNUM *)0x0) goto LAB_0012c7d0;
        pBVar1 = BN_copy(a_00,(BIGNUM *)param_1[0x12]);
        if (pBVar1 == (BIGNUM *)0x0) {
          pBVar1 = (BIGNUM *)0x0;
          goto LAB_0012c7d0;
        }
      }
      else {
        pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x9c))(param_1,a,param_1[0x11],param_2);
        if ((pBVar1 == (BIGNUM *)0x0) ||
           (pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x9c))(param_1,a_00,param_1[0x12],param_2),
           pBVar1 == (BIGNUM *)0x0)) goto LAB_0012c7d0;
      }
      iVar2 = BN_is_zero(a);
      if (iVar2 == 0) {
        pBVar1 = (BIGNUM *)0x1;
        iVar2 = BN_is_zero(a_00);
        if ((((iVar2 == 0) &&
             (pBVar1 = (BIGNUM *)BN_mod_sqr(r,a,m,param_2), pBVar1 != (BIGNUM *)0x0)) &&
            (pBVar1 = (BIGNUM *)BN_mod_mul(r_00,r,a,m,param_2), pBVar1 != (BIGNUM *)0x0)) &&
           (((pBVar1 = (BIGNUM *)BN_lshift(r,r_00,2), pBVar1 != (BIGNUM *)0x0 &&
             (pBVar1 = (BIGNUM *)BN_mod_sqr(r_00,a_00,m,param_2), pBVar1 != (BIGNUM *)0x0)) &&
            ((pBVar1 = (BIGNUM *)BN_mul_word(r_00,0x1b), pBVar1 != (BIGNUM *)0x0 &&
             (pBVar1 = (BIGNUM *)BN_mod_add(a,r,r_00,m,param_2), pBVar1 != (BIGNUM *)0x0)))))) {
          iVar2 = BN_is_zero(a);
          pBVar1 = (BIGNUM *)(uint)(iVar2 == 0);
        }
      }
      else {
        iVar2 = BN_is_zero(a_00);
        pBVar1 = (BIGNUM *)(uint)(iVar2 == 0);
      }
    }
  }
LAB_0012c7d0:
  BN_CTX_end(param_2);
  BN_CTX_free(c);
  return pBVar1;
}

