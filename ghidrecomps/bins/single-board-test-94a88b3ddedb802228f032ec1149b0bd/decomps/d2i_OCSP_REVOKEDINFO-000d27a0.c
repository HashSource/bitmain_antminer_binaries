
OCSP_REVOKEDINFO * d2i_OCSP_REVOKEDINFO(OCSP_REVOKEDINFO **a,uchar **in,long len)

{
  OCSP_REVOKEDINFO *pOVar1;
  
  pOVar1 = (OCSP_REVOKEDINFO *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d27a8);
  return pOVar1;
}

