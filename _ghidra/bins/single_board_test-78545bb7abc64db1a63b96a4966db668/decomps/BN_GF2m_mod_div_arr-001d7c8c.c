
undefined4
BN_GF2m_mod_div_arr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  undefined4 uVar3;
  
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  if ((pBVar1 == (BIGNUM *)0x0) || (iVar2 = BN_GF2m_arr2poly(param_4,pBVar1), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = BN_GF2m_mod_div(param_1,param_2,param_3,pBVar1,param_5);
  }
  BN_CTX_end(param_5);
  return uVar3;
}

