
OCSP_REQUEST * d2i_OCSP_REQUEST(OCSP_REQUEST **a,uchar **in,long len)

{
  OCSP_REQUEST *pOVar1;
  
  pOVar1 = (OCSP_REQUEST *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d26e8);
  return pOVar1;
}

