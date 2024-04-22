
int OCSP_resp_count(OCSP_BASICRESP *bs)

{
  int iVar1;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    iVar1 = sk_num(&bs->tbsResponseData->responses->stack);
    return iVar1;
  }
  return -1;
}

