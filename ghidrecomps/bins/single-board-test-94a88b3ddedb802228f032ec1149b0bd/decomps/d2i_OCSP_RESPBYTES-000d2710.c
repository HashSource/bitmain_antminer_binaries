
OCSP_RESPBYTES * d2i_OCSP_RESPBYTES(OCSP_RESPBYTES **a,uchar **in,long len)

{
  OCSP_RESPBYTES *pOVar1;
  
  pOVar1 = (OCSP_RESPBYTES *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d2718);
  return pOVar1;
}

