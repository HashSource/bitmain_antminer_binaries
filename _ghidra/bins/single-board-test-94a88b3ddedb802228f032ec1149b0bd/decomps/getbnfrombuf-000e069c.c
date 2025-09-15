
BIGNUM * getbnfrombuf(uchar *param_1,int param_2)

{
  BIGNUM *pBVar1;
  
  if (*param_1 == '\0') {
    if (param_2 != 0) {
      param_1 = param_1 + 1;
      do {
        param_2 = param_2 + -1;
        if (*param_1 != '\0') goto LAB_000e06b6;
        param_1 = param_1 + 1;
      } while (param_2 != 0);
    }
  }
  else {
LAB_000e06b6:
    if (param_2 != 0) {
      pBVar1 = BN_bin2bn(param_1,param_2,(BIGNUM *)0x0);
      return pBVar1;
    }
  }
  pBVar1 = BN_new();
  BN_set_word(pBVar1,0);
  return pBVar1;
}

