
ASIdentifiers * d2i_ASIdentifiers(ASIdentifiers **a,uchar **in,long len)

{
  ASIdentifiers *pAVar1;
  
  pAVar1 = (ASIdentifiers *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&ASIdentifiers_it);
  return pAVar1;
}

