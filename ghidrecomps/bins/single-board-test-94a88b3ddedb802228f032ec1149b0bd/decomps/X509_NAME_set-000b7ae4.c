
int X509_NAME_set(X509_NAME **xn,X509_NAME *name)

{
  X509_NAME *pXVar1;
  
  if (xn != (X509_NAME **)0x0 && name != (X509_NAME *)0x0) {
    pXVar1 = *xn;
    if (pXVar1 != name) {
      pXVar1 = (X509_NAME *)ASN1_item_dup(DAT_000b7b1c,name);
      if (pXVar1 == (X509_NAME *)0x0) {
        pXVar1 = *xn;
      }
      else {
        ASN1_item_free((ASN1_VALUE *)*xn,DAT_000b7b1c);
        *xn = pXVar1;
      }
    }
    if (pXVar1 != (X509_NAME *)0x0) {
      pXVar1 = (X509_NAME *)0x1;
    }
    return (int)pXVar1;
  }
  return 0;
}

