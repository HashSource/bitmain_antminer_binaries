
ASN1_T61STRING * d2i_ASN1_T61STRING(ASN1_T61STRING **a,uchar **in,long len)

{
  ASN1_T61STRING *pAVar1;
  
  pAVar1 = (ASN1_T61STRING *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_T61STRING_it);
  return pAVar1;
}

