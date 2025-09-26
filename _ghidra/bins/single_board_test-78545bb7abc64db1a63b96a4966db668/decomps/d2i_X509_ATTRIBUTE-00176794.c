
X509_ATTRIBUTE * d2i_X509_ATTRIBUTE(X509_ATTRIBUTE **a,uchar **in,long len)

{
  X509_ATTRIBUTE *pXVar1;
  
  pXVar1 = (X509_ATTRIBUTE *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&X509_ATTRIBUTE_it);
  return pXVar1;
}

