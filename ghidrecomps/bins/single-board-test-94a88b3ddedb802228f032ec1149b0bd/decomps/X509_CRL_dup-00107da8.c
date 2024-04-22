
X509_CRL * X509_CRL_dup(X509_CRL *crl)

{
  X509_CRL *pXVar1;
  
  pXVar1 = (X509_CRL *)ASN1_item_dup(DAT_00107db0,crl);
  return pXVar1;
}

