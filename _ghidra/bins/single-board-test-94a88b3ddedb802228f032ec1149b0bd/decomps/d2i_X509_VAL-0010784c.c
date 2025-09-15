
X509_VAL * d2i_X509_VAL(X509_VAL **a,uchar **in,long len)

{
  X509_VAL *pXVar1;
  
  pXVar1 = (X509_VAL *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&X509_VAL_it);
  return pXVar1;
}

