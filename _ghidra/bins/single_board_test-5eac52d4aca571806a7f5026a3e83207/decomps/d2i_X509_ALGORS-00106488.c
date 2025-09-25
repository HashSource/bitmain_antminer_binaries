
X509_ALGORS * d2i_X509_ALGORS(X509_ALGORS **a,uchar **in,long len)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&X509_ALGORS_it);
  return (X509_ALGORS *)pAVar1;
}

