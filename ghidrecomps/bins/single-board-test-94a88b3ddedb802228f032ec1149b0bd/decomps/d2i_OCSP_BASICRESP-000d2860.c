
OCSP_BASICRESP * d2i_OCSP_BASICRESP(OCSP_BASICRESP **a,uchar **in,long len)

{
  OCSP_BASICRESP *pOVar1;
  
  pOVar1 = (OCSP_BASICRESP *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d2868);
  return pOVar1;
}

