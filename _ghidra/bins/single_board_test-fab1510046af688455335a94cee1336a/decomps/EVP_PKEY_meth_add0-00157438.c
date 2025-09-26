
int EVP_PKEY_meth_add0(EVP_PKEY_METHOD *pmeth)

{
  int iVar1;
  
  if (((app_pkey_methods == (_STACK *)0x0) &&
      (app_pkey_methods = sk_new((cmp *)0x156fad), app_pkey_methods == (_STACK *)0x0)) ||
     (iVar1 = sk_push(app_pkey_methods,pmeth), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    sk_sort(app_pkey_methods);
    iVar1 = 1;
  }
  return iVar1;
}

