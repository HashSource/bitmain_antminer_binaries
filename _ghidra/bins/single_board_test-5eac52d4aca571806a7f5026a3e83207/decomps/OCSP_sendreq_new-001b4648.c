
OCSP_REQ_CTX * OCSP_sendreq_new(BIO *io,char *path,OCSP_REQUEST *req,int maxline)

{
  OCSP_REQ_CTX *rctx;
  int iVar1;
  
  rctx = (OCSP_REQ_CTX *)OCSP_REQ_CTX_new(io,maxline);
  if (rctx != (OCSP_REQ_CTX *)0x0) {
    iVar1 = OCSP_REQ_CTX_http(rctx,&DAT_00232004,path);
    if ((iVar1 != 0) &&
       ((req == (OCSP_REQUEST *)0x0 || (iVar1 = OCSP_REQ_CTX_set1_req(rctx,req), iVar1 != 0)))) {
      return rctx;
    }
    OCSP_REQ_CTX_free(rctx);
  }
  return (OCSP_REQ_CTX *)0x0;
}

