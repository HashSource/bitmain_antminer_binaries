
int OCSP_copy_nonce(OCSP_BASICRESP *resp,OCSP_REQUEST *req)

{
  int iVar1;
  X509_EXTENSION *ex;
  
  iVar1 = OCSP_REQUEST_get_ext_by_NID(req,0x16e,-1);
  if (iVar1 < 0) {
    return 2;
  }
  ex = OCSP_REQUEST_get_ext(req,iVar1);
  iVar1 = OCSP_BASICRESP_add_ext(resp,ex,-1);
  return iVar1;
}

