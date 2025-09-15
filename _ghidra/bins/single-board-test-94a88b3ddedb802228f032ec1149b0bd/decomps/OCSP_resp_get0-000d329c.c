
OCSP_SINGLERESP * OCSP_resp_get0(OCSP_BASICRESP *bs,int idx)

{
  OCSP_SINGLERESP *pOVar1;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    pOVar1 = (OCSP_SINGLERESP *)sk_value(&bs->tbsResponseData->responses->stack,idx);
    return pOVar1;
  }
  return (OCSP_SINGLERESP *)0x0;
}

