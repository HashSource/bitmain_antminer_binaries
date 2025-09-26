
int OSSL_STORE_INFO_get0_NAME_description(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 1) {
    iVar1 = param_1[2];
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

