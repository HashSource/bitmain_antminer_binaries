
OCSP_RESPONSE * OCSP_sendreq_bio(BIO *b,char *path,OCSP_REQUEST *req)

{
  OCSP_REQ_CTX *rctx;
  int iVar1;
  OCSP_RESPONSE *local_1c [2];
  
  local_1c[0] = (OCSP_RESPONSE *)0x0;
  rctx = OCSP_sendreq_new(b,path,req,-1);
  if (rctx != (OCSP_REQ_CTX *)0x0) {
    while (iVar1 = OCSP_sendreq_nbio(local_1c,rctx), iVar1 == -1) {
      iVar1 = BIO_test_flags(b,8);
      if (iVar1 == 0) {
        OCSP_REQ_CTX_free(rctx);
        return local_1c[0];
      }
    }
    OCSP_REQ_CTX_free(rctx);
    if (iVar1 != 0) {
      return local_1c[0];
    }
  }
  return (OCSP_RESPONSE *)0x0;
}

