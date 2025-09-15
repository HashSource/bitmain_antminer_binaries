
X509_CRL * d2i_X509_CRL_fp(FILE *fp,X509_CRL **crl)

{
  X509_CRL *pXVar1;
  
  pXVar1 = (X509_CRL *)ASN1_item_d2i_fp((ASN1_ITEM *)X509_CRL_it,fp,crl);
  return pXVar1;
}

