
BIGNUM * BN_GF2m_mod_exp_arr(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,undefined4 param_4,
                            BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  int iVar3;
  
  iVar1 = BN_is_zero(param_3);
  if (iVar1 != 0) {
    pBVar2 = (BIGNUM *)BN_set_word(param_1,1);
    return pBVar2;
  }
  iVar1 = BN_abs_is_word(param_3,1);
  if (iVar1 != 0) {
    pBVar2 = BN_copy(param_1,param_2);
    if (pBVar2 != (BIGNUM *)0x0) {
      pBVar2 = (BIGNUM *)0x1;
    }
    return pBVar2;
  }
  BN_CTX_start(param_5);
  pBVar2 = BN_CTX_get(param_5);
  if ((pBVar2 == (BIGNUM *)0x0) || (iVar1 = BN_GF2m_mod_arr(pBVar2,param_2,param_4), iVar1 == 0)) {
LAB_001d70bc:
    pBVar2 = (BIGNUM *)0x0;
  }
  else {
    iVar3 = BN_num_bits(param_3);
    iVar1 = iVar3 + -2;
    if (-1 < iVar3 + -2) {
      do {
        iVar3 = BN_GF2m_mod_sqr_arr(pBVar2,pBVar2,param_4,param_5);
        if (iVar3 == 0) goto LAB_001d70bc;
        iVar3 = iVar1 + -1;
        iVar1 = BN_is_bit_set(param_3,iVar1);
        if ((iVar1 != 0) &&
           (iVar1 = BN_GF2m_mod_mul_arr(pBVar2,pBVar2,param_2,param_4,param_5), iVar1 == 0))
        goto LAB_001d70bc;
        iVar1 = iVar3;
      } while (iVar3 != -1);
    }
    pBVar2 = BN_copy(param_1,pBVar2);
    if (pBVar2 != (BIGNUM *)0x0) {
      pBVar2 = (BIGNUM *)0x1;
    }
  }
  BN_CTX_end(param_5);
  return pBVar2;
}

