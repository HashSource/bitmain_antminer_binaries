
X509_ALGOR * d2i_X509_ALGOR(X509_ALGOR **a,uchar **in,long len)

{
  X509_ALGOR *pXVar1;
  
  pXVar1 = (X509_ALGOR *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&X509_ALGOR_it);
  return pXVar1;
}

