
ASN1_UTCTIME * d2i_ASN1_UTCTIME(ASN1_UTCTIME **a,uchar **in,long len)

{
  ASN1_UTCTIME *pAVar1;
  
  pAVar1 = (ASN1_UTCTIME *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_UTCTIME_it);
  return pAVar1;
}

