
int OSSL_STORE_INFO_get0_CRL(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 5) {
    iVar1 = param_1[1];
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

