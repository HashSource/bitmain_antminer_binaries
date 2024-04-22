
SXNETID * d2i_SXNETID(SXNETID **a,uchar **in,long len)

{
  SXNETID *pSVar1;
  
  pSVar1 = (SXNETID *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&SXNETID_it);
  return pSVar1;
}

