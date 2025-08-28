
ASN1_IA5STRING * d2i_ASN1_IA5STRING(ASN1_IA5STRING **a,uchar **in,long len)

{
  ASN1_IA5STRING *pAVar1;
  
  pAVar1 = (ASN1_IA5STRING *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_IA5STRING_it);
  return pAVar1;
}

