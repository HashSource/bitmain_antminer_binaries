
int X509_set_issuer_name(X509 *x,X509_NAME *name)

{
  int iVar1;
  
  if (x != (X509 *)0x0) {
    iVar1 = X509_NAME_set((X509_NAME **)&(x->ex_data).dummy,name);
    return iVar1;
  }
  return 0;
}

