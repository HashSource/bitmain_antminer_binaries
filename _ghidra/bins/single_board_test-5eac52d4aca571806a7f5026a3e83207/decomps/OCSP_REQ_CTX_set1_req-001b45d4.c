
int OCSP_REQ_CTX_set1_req(OCSP_REQ_CTX *rctx,OCSP_REQUEST *req)

{
  int iVar1;
  
  iVar1 = OCSP_REQ_CTX_i2d(rctx,OCSP_REQUEST_it,req);
  return iVar1;
}

