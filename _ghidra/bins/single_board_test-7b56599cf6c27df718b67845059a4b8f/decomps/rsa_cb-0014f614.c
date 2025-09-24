
undefined4 rsa_cb(int param_1,int *param_2)

{
  int iVar1;
  RSA *pRVar2;
  
  if (param_1 == 0) {
    pRVar2 = RSA_new();
    *param_2 = (int)pRVar2;
    if (pRVar2 == (RSA *)0x0) {
      return 0;
    }
    return 2;
  }
  if (param_1 != 2) {
    if ((param_1 == 5) && (*(int *)(*param_2 + 4) == 1)) {
      iVar1 = rsa_multip_calc_product();
      if (iVar1 != 1) {
        return 0;
      }
      return 2;
    }
    return 1;
  }
  RSA_free((RSA *)*param_2);
  *param_2 = 0;
  return 2;
}

