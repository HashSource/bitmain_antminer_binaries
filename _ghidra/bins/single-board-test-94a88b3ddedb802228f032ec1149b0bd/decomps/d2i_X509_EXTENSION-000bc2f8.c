
X509_EXTENSION * d2i_X509_EXTENSION(X509_EXTENSION **a,uchar **in,long len)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = (X509_EXTENSION *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&X509_EXTENSION_it);
  return pXVar1;
}

