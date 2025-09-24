
int X509_NAME_set(X509_NAME **xn,X509_NAME *name)

{
  X509_NAME *pXVar1;
  
  pXVar1 = *xn;
  if (pXVar1 == name) {
    if (pXVar1 != (X509_NAME *)0x0) {
      pXVar1 = (X509_NAME *)0x1;
    }
    return (int)pXVar1;
  }
  pXVar1 = X509_NAME_dup(name);
  if (pXVar1 != (X509_NAME *)0x0) {
    X509_NAME_free(*xn);
    *xn = pXVar1;
    return 1;
  }
  return 0;
}

