
uint ossl_tolower(uint param_1)

{
  int iVar1;
  
  iVar1 = ossl_ctype_check(param_1,2);
  if (iVar1 != 0) {
    return param_1 ^ 0x20;
  }
  return param_1;
}

