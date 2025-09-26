
X509_CRL_INFO * d2i_X509_CRL_INFO(X509_CRL_INFO **a,uchar **in,long len)

{
  X509_CRL_INFO *pXVar1;
  
  pXVar1 = (X509_CRL_INFO *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&X509_CRL_INFO_it);
  return pXVar1;
}

