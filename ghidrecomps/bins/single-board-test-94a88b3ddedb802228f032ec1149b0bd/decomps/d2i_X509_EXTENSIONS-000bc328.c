
X509_EXTENSIONS * d2i_X509_EXTENSIONS(X509_EXTENSIONS **a,uchar **in,long len)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)X509_EXTENSIONS_it);
  return (X509_EXTENSIONS *)pAVar1;
}

