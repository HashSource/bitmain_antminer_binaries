
EDIPARTYNAME * d2i_EDIPARTYNAME(EDIPARTYNAME **a,uchar **in,long len)

{
  EDIPARTYNAME *pEVar1;
  
  pEVar1 = (EDIPARTYNAME *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000c87ec);
  return pEVar1;
}

