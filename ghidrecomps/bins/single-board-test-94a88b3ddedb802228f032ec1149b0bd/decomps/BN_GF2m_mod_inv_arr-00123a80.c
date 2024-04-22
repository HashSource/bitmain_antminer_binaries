
undefined4 BN_GF2m_mod_inv_arr(undefined4 param_1,undefined4 param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  undefined4 uVar1;
  int iVar2;
  
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  if (a == (BIGNUM *)0x0) {
LAB_00123abc:
    uVar1 = 0;
  }
  else {
    BN_set_word(a,0);
    iVar2 = *param_3;
    while (iVar2 != -1) {
      iVar2 = BN_set_bit(a,iVar2);
      if (iVar2 == 0) goto LAB_00123abc;
      param_3 = param_3 + 1;
      iVar2 = *param_3;
    }
    uVar1 = BN_GF2m_mod_inv(param_1,param_2,a,param_4);
  }
  BN_CTX_end(param_4);
  return uVar1;
}

