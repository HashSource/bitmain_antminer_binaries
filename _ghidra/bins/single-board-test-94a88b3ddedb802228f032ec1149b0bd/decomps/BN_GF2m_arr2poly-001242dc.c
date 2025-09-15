
undefined4 BN_GF2m_arr2poly(int *param_1,BIGNUM *param_2)

{
  int iVar1;
  
  BN_set_word(param_2,0);
  iVar1 = *param_1;
  while( true ) {
    if (iVar1 == -1) {
      return 1;
    }
    iVar1 = BN_set_bit(param_2,iVar1);
    if (iVar1 == 0) break;
    param_1 = param_1 + 1;
    iVar1 = *param_1;
  }
  return 0;
}

