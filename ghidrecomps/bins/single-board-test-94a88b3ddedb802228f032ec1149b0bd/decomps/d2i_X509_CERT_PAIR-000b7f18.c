
X509_CERT_PAIR * d2i_X509_CERT_PAIR(X509_CERT_PAIR **a,uchar **in,long len)

{
  X509_CERT_PAIR *pXVar1;
  
  pXVar1 = (X509_CERT_PAIR *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000b7f20);
  return pXVar1;
}

