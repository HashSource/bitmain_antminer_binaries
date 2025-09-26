
OCSP_REQ_CTX *
OCSP_REQ_CTX_new(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  OCSP_REQ_CTX *rctx;
  BIO_METHOD *type;
  BIO *pBVar1;
  void *pvVar2;
  
  rctx = (OCSP_REQ_CTX *)CRYPTO_zalloc(0x1c,"crypto/ocsp/ocsp_ht.c",0x42,param_4,param_4);
  if (rctx != (OCSP_REQ_CTX *)0x0) {
    *(undefined4 *)(rctx + 0x18) = 0x19000;
    *(undefined4 *)rctx = 0x1000;
    type = BIO_s_mem();
    pBVar1 = BIO_new(type);
    *(BIO **)(rctx + 0x10) = pBVar1;
    if (param_2 < 1) {
      param_2 = 0x1000;
    }
    *(undefined4 *)(rctx + 0xc) = param_1;
    *(int *)(rctx + 8) = param_2;
    pvVar2 = CRYPTO_malloc(param_2,"crypto/ocsp/ocsp_ht.c",0x4e);
    *(void **)(rctx + 4) = pvVar2;
    if ((pvVar2 != (void *)0x0) && (*(int *)(rctx + 0x10) != 0)) {
      return rctx;
    }
    OCSP_REQ_CTX_free(rctx);
  }
  return (OCSP_REQ_CTX *)0x0;
}

