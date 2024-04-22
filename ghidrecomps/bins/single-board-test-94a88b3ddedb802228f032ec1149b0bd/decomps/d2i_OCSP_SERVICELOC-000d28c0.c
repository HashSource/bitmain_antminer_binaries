
OCSP_SERVICELOC * d2i_OCSP_SERVICELOC(OCSP_SERVICELOC **a,uchar **in,long len)

{
  OCSP_SERVICELOC *pOVar1;
  
  pOVar1 = (OCSP_SERVICELOC *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d28c8);
  return pOVar1;
}

