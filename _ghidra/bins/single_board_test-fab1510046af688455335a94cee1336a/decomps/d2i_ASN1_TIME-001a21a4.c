
ASN1_TIME * d2i_ASN1_TIME(ASN1_TIME **a,uchar **in,long len)

{
  ASN1_TIME *pAVar1;
  
  pAVar1 = (ASN1_TIME *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&ASN1_TIME_it);
  return pAVar1;
}

