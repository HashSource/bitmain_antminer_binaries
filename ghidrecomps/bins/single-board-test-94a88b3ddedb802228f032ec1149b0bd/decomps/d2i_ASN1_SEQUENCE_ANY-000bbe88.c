
ASN1_SEQUENCE_ANY * d2i_ASN1_SEQUENCE_ANY(ASN1_SEQUENCE_ANY **a,uchar **in,long len)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_SEQUENCE_ANY_it);
  return (ASN1_SEQUENCE_ANY *)pAVar1;
}

