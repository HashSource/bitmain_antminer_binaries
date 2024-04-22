
OCSP_CERTID * d2i_OCSP_CERTID(OCSP_CERTID **a,uchar **in,long len)

{
  OCSP_CERTID *pOVar1;
  
  pOVar1 = (OCSP_CERTID *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000d2658);
  return pOVar1;
}

