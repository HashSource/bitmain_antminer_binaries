
POLICYINFO * d2i_POLICYINFO(POLICYINFO **a,uchar **in,long len)

{
  POLICYINFO *pPVar1;
  
  pPVar1 = (POLICYINFO *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&POLICYINFO_it);
  return pPVar1;
}

