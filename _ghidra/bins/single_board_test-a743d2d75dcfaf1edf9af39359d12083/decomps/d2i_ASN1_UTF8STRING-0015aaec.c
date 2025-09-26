
ASN1_UTF8STRING * d2i_ASN1_UTF8STRING(ASN1_UTF8STRING **a,uchar **in,long len)

{
  ASN1_UTF8STRING *pAVar1;
  
  pAVar1 = (ASN1_UTF8STRING *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_UTF8STRING_it)
  ;
  return pAVar1;
}

