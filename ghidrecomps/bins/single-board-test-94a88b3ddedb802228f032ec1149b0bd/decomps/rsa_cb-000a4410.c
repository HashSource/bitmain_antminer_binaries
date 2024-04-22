
undefined4 rsa_cb(int param_1,RSA **param_2)

{
  RSA *pRVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    pRVar1 = RSA_new();
    *param_2 = pRVar1;
    if (pRVar1 == (RSA *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 2;
    }
    return uVar2;
  }
  if (param_1 == 2) {
    RSA_free(*param_2);
    *param_2 = (RSA *)0x0;
    return 2;
  }
  return 1;
}

