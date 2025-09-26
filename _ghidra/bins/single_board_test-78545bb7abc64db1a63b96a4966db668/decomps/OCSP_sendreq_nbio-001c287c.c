
int OCSP_sendreq_nbio(OCSP_RESPONSE **presp,OCSP_REQ_CTX *rctx)

{
  int iVar1;
  
  iVar1 = OCSP_REQ_CTX_nbio_d2i(rctx,presp,OCSP_RESPONSE_it);
  return iVar1;
}

