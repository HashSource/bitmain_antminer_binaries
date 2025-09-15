
NETSCAPE_SPKAC * d2i_NETSCAPE_SPKAC(NETSCAPE_SPKAC **a,uchar **in,long len)

{
  NETSCAPE_SPKAC *pNVar1;
  
  pNVar1 = (NETSCAPE_SPKAC *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&NETSCAPE_SPKAC_it);
  return pNVar1;
}

