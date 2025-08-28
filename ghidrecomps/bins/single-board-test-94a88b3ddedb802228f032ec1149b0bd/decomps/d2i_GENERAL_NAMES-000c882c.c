
GENERAL_NAMES * d2i_GENERAL_NAMES(GENERAL_NAMES **a,uchar **in,long len)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)GENERAL_NAMES_it);
  return (GENERAL_NAMES *)pAVar1;
}

