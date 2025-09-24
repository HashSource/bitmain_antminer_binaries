
int OCSP_resp_count(OCSP_BASICRESP *bs)

{
  int iVar1;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    iVar1 = OPENSSL_sk_num(bs[1].tbsResponseData);
    return iVar1;
  }
  return -1;
}

