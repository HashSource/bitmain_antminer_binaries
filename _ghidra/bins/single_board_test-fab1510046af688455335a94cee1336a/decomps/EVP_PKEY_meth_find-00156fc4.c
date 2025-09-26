
EVP_PKEY_METHOD * EVP_PKEY_meth_find(int type)

{
  int iVar1;
  EVP_PKEY_METHOD *pEVar2;
  int *local_78;
  int local_74 [27];
  
  local_78 = local_74;
  local_74[0] = type;
  if ((app_pkey_methods == (_STACK *)0x0) || (iVar1 = sk_find(app_pkey_methods,local_78), iVar1 < 0)
     ) {
    pEVar2 = (EVP_PKEY_METHOD *)OBJ_bsearch_(&local_78,&standard_methods,7,4,(cmp *)0x156fb9);
    if (pEVar2 != (EVP_PKEY_METHOD *)0x0) {
      pEVar2 = *(EVP_PKEY_METHOD **)pEVar2;
    }
  }
  else {
    pEVar2 = (EVP_PKEY_METHOD *)sk_value(app_pkey_methods,iVar1);
  }
  return pEVar2;
}

