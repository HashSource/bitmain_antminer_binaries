
OCSP_RESPDATA * d2i_OCSP_RESPDATA(OCSP_RESPDATA **a,uchar **in,long len)

{
  OCSP_RESPDATA *pOVar1;
  
  pOVar1 = (OCSP_RESPDATA *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d2838);
  return pOVar1;
}

