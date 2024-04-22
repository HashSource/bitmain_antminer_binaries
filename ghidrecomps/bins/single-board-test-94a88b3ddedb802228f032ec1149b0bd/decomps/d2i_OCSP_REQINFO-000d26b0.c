
OCSP_REQINFO * d2i_OCSP_REQINFO(OCSP_REQINFO **a,uchar **in,long len)

{
  OCSP_REQINFO *pOVar1;
  
  pOVar1 = (OCSP_REQINFO *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d26b8);
  return pOVar1;
}

