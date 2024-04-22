
X509_NAME * X509_NAME_dup(X509_NAME *xn)

{
  X509_NAME *pXVar1;
  
  pXVar1 = (X509_NAME *)ASN1_item_dup(DAT_000b7ae0,xn);
  return pXVar1;
}

