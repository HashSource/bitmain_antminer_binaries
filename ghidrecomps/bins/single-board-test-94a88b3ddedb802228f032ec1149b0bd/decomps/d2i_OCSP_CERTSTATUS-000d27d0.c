
OCSP_CERTSTATUS * d2i_OCSP_CERTSTATUS(OCSP_CERTSTATUS **a,uchar **in,long len)

{
  OCSP_CERTSTATUS *pOVar1;
  
  pOVar1 = (OCSP_CERTSTATUS *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d27d8);
  return pOVar1;
}

