
EDIPARTYNAME * d2i_EDIPARTYNAME(EDIPARTYNAME **a,uchar **in,long len)

{
  EDIPARTYNAME *pEVar1;
  
  pEVar1 = (EDIPARTYNAME *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)EDIPARTYNAME_it);
  return pEVar1;
}

