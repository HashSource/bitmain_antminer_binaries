
ASN1_ENUMERATED * d2i_ASN1_ENUMERATED(ASN1_ENUMERATED **a,uchar **in,long len)

{
  ASN1_ENUMERATED *pAVar1;
  
  pAVar1 = (ASN1_ENUMERATED *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_ENUMERATED_it)
  ;
  return pAVar1;
}

