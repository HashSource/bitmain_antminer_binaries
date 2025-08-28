
OCSP_SINGLERESP * d2i_OCSP_SINGLERESP(OCSP_SINGLERESP **a,uchar **in,long len)

{
  OCSP_SINGLERESP *pOVar1;
  
  pOVar1 = (OCSP_SINGLERESP *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)OCSP_SINGLERESP_it)
  ;
  return pOVar1;
}

