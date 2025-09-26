
EVP_PKEY_METHOD * EVP_PKEY_meth_find(int type)

{
  int iVar1;
  EVP_PKEY_METHOD *pEVar2;
  int *local_90;
  int local_8c [33];
  
  local_90 = local_8c;
  local_8c[0] = type;
  if ((app_pkey_methods != 0) && (iVar1 = OPENSSL_sk_find(), -1 < iVar1)) {
    pEVar2 = (EVP_PKEY_METHOD *)OPENSSL_sk_value(app_pkey_methods);
    return pEVar2;
  }
  pEVar2 = (EVP_PKEY_METHOD *)OBJ_bsearch_(&local_90,&standard_methods,0x12,4,(cmp *)0x13cc61);
  if (pEVar2 != (EVP_PKEY_METHOD *)0x0) {
    pEVar2 = *(EVP_PKEY_METHOD **)pEVar2;
  }
  return pEVar2;
}

