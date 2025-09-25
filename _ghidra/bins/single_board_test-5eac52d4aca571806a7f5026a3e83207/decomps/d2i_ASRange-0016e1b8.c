
ASRange * d2i_ASRange(ASRange **a,uchar **in,long len)

{
  ASRange *pAVar1;
  
  pAVar1 = (ASRange *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASRange_it);
  return pAVar1;
}

