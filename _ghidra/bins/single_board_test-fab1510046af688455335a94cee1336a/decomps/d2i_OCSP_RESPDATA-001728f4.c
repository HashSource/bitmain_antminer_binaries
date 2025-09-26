
OCSP_RESPDATA * d2i_OCSP_RESPDATA(OCSP_RESPDATA **a,uchar **in,long len)

{
  OCSP_RESPDATA *pOVar1;
  
  pOVar1 = (OCSP_RESPDATA *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)OCSP_RESPDATA_it);
  return pOVar1;
}

