
X509_VERIFY_PARAM * X509_VERIFY_PARAM_lookup(char *name)

{
  int iVar1;
  X509_VERIFY_PARAM *pXVar2;
  char *local_50 [17];
  
  local_50[0] = name;
  if ((param_table != 0) && (iVar1 = OPENSSL_sk_find(param_table,local_50), -1 < iVar1)) {
    pXVar2 = (X509_VERIFY_PARAM *)OPENSSL_sk_value(param_table);
    return pXVar2;
  }
  pXVar2 = (X509_VERIFY_PARAM *)OBJ_bsearch_(local_50,&default_table,5,0x40,(cmp *)0x174d8d);
  return pXVar2;
}

