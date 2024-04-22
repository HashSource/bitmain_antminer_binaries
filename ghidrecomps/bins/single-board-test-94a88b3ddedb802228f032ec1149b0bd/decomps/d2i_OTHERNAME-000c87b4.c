
OTHERNAME * d2i_OTHERNAME(OTHERNAME **a,uchar **in,long len)

{
  OTHERNAME *pOVar1;
  
  pOVar1 = (OTHERNAME *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000c87bc);
  return pOVar1;
}

