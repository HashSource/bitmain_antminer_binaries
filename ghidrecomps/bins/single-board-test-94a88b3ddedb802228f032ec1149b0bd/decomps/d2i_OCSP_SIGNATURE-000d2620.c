
OCSP_SIGNATURE * d2i_OCSP_SIGNATURE(OCSP_SIGNATURE **a,uchar **in,long len)

{
  OCSP_SIGNATURE *pOVar1;
  
  pOVar1 = (OCSP_SIGNATURE *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&OCSP_SIGNATURE_it);
  return pOVar1;
}

