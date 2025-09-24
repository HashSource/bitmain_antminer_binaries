
int bn_print(BIO *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = BN_print(param_1,(BIGNUM *)*param_2);
  if (iVar1 != 0) {
    iVar1 = BIO_puts(param_1,"\n");
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}

