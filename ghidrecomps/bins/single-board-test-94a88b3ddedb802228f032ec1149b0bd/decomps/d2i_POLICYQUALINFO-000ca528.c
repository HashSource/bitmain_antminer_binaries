
POLICYQUALINFO * d2i_POLICYQUALINFO(POLICYQUALINFO **a,uchar **in,long len)

{
  POLICYQUALINFO *pPVar1;
  
  pPVar1 = (POLICYQUALINFO *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000ca530);
  return pPVar1;
}

