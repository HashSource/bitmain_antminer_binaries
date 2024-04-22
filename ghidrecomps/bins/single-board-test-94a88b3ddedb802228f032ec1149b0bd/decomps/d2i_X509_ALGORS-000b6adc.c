
X509_ALGORS * d2i_X509_ALGORS(X509_ALGORS **a,uchar **in,long len)

{
  X509_ALGORS *pXVar1;
  
  pXVar1 = (X509_ALGORS *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000b6ae4);
  return pXVar1;
}

