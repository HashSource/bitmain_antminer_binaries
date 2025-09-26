
ASIdOrRange * d2i_ASIdOrRange(ASIdOrRange **a,uchar **in,long len)

{
  ASIdOrRange *pAVar1;
  
  pAVar1 = (ASIdOrRange *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASIdOrRange_it);
  return pAVar1;
}

