
BIGNUM * BN_GF2m_mod_solve_quad_arr
                   (BIGNUM *param_1,undefined4 param_2,uint *param_3,BN_CTX *param_4)

{
  BIGNUM *b;
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *pBVar6;
  int local_2c;
  
  if (*param_3 == 0) {
    BN_set_word(param_1,0);
    return (BIGNUM *)0x1;
  }
  BN_CTX_start(param_4);
  b = BN_CTX_get(param_4);
  a = BN_CTX_get(param_4);
  a_00 = BN_CTX_get(param_4);
  if ((a_00 == (BIGNUM *)0x0) || (iVar1 = BN_GF2m_mod_arr(b,param_2,param_3), iVar1 == 0))
  goto LAB_001cd602;
  iVar1 = BN_is_zero(b);
  if (iVar1 != 0) {
    BN_set_word(param_1,0);
    pBVar6 = (BIGNUM *)0x1;
    goto LAB_001cd606;
  }
  if ((*param_3 & 1) == 0) {
    pBVar6 = BN_CTX_get(param_4);
    pBVar2 = BN_CTX_get(param_4);
    pBVar3 = BN_CTX_get(param_4);
    if (pBVar3 != (BIGNUM *)0x0) {
      local_2c = 0;
      do {
        iVar1 = BN_priv_rand(pBVar6,*param_3,0);
        if ((iVar1 == 0) || (iVar1 = BN_GF2m_mod_arr(pBVar6,pBVar6,param_3), iVar1 == 0))
        goto LAB_001cd602;
        BN_set_word(a,0);
        pBVar4 = BN_copy(a_00,pBVar6);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_001cd602;
        if (1 < (int)*param_3) {
          iVar1 = 1;
          do {
            iVar1 = iVar1 + 1;
            iVar5 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4);
            if (((iVar5 == 0) ||
                (iVar5 = BN_GF2m_mod_sqr_arr(pBVar2,a_00,param_3,param_4), iVar5 == 0)) ||
               ((iVar5 = BN_GF2m_mod_mul_arr(pBVar3,pBVar2,b,param_3,param_4), iVar5 == 0 ||
                ((iVar5 = BN_GF2m_add(a,a,pBVar3), iVar5 == 0 ||
                 (iVar5 = BN_GF2m_add(a_00,pBVar2,pBVar6), iVar5 == 0)))))) goto LAB_001cd602;
          } while (iVar1 < (int)*param_3);
        }
        local_2c = local_2c + 1;
        iVar1 = BN_is_zero(a_00);
      } while (local_2c != 0x32 && iVar1 != 0);
      pBVar6 = (BIGNUM *)0x0;
      iVar1 = BN_is_zero(a_00);
      if (iVar1 != 0) {
        ERR_put_error(3,0x87,0x71,"crypto/bn/bn_gf2m.c",0x420);
        goto LAB_001cd606;
      }
LAB_001cd768:
      iVar1 = BN_GF2m_mod_sqr_arr(a_00,a,param_3,param_4);
      if ((iVar1 != 0) && (iVar1 = BN_GF2m_add(a_00,a,a_00), iVar1 != 0)) {
        iVar1 = BN_ucmp(a_00,b);
        if (iVar1 == 0) {
          pBVar6 = BN_copy(param_1,a);
          if (pBVar6 != (BIGNUM *)0x0) {
            pBVar6 = (BIGNUM *)0x1;
          }
          goto LAB_001cd606;
        }
        ERR_put_error(3,0x87,0x74,"crypto/bn/bn_gf2m.c",0x42a);
      }
    }
  }
  else {
    pBVar6 = BN_copy(a,b);
    if (pBVar6 != (BIGNUM *)0x0) {
      if (2 < (int)*param_3) {
        iVar1 = 1;
        do {
          iVar1 = iVar1 + 1;
          iVar5 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4);
          if (((iVar5 == 0) || (iVar5 = BN_GF2m_mod_sqr_arr(a,a,param_3,param_4), iVar5 == 0)) ||
             (iVar5 = BN_GF2m_add(a,a,b), iVar5 == 0)) goto LAB_001cd602;
        } while (iVar1 <= (int)(*param_3 - 1) / 2);
      }
      goto LAB_001cd768;
    }
  }
LAB_001cd602:
  pBVar6 = (BIGNUM *)0x0;
LAB_001cd606:
  BN_CTX_end(param_4);
  return pBVar6;
}

