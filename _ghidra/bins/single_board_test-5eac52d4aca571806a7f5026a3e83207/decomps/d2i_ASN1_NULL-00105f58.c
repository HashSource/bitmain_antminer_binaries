
ASN1_NULL * d2i_ASN1_NULL(ASN1_NULL **a,uchar **in,long len)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_NULL_it);
  return (ASN1_NULL *)pAVar1;
}

