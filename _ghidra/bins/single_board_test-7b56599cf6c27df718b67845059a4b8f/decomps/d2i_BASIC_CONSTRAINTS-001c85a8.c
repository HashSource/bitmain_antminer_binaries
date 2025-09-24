
BASIC_CONSTRAINTS * d2i_BASIC_CONSTRAINTS(BASIC_CONSTRAINTS **a,uchar **in,long len)

{
  BASIC_CONSTRAINTS *pBVar1;
  
  pBVar1 = (BASIC_CONSTRAINTS *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&BASIC_CONSTRAINTS_it);
  return pBVar1;
}

