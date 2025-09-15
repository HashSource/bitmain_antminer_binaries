
int BN_GF2m_mod_div_arr(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                       BN_CTX *param_5)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  int iVar2;
  
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  if (a == (BIGNUM *)0x0) {
LAB_00123b70:
    iVar2 = 0;
  }
  else {
    BN_set_word(a,0);
    iVar2 = *param_4;
    while (iVar2 != -1) {
      iVar2 = BN_set_bit(a,iVar2);
      if (iVar2 == 0) goto LAB_00123b70;
      param_4 = param_4 + 1;
      iVar2 = *param_4;
    }
    BN_CTX_start(param_5);
    pBVar1 = BN_CTX_get(param_5);
    if ((pBVar1 == (BIGNUM *)0x0) || (iVar2 = BN_GF2m_mod_inv(pBVar1,param_3,a,param_5), iVar2 == 0)
       ) {
      iVar2 = 0;
    }
    else {
      iVar2 = BN_GF2m_mod_mul(param_1,param_2,pBVar1,a,param_5);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
    }
    BN_CTX_end(param_5);
  }
  BN_CTX_end(param_5);
  return iVar2;
}

