
X509_CINF * d2i_X509_CINF(X509_CINF **a,uchar **in,long len)

{
  X509_CINF *pXVar1;
  
  pXVar1 = (X509_CINF *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&X509_CINF_it);
  return pXVar1;
}

