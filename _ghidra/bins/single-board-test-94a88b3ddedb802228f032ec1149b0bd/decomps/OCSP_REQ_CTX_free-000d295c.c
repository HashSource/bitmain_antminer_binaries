
void OCSP_REQ_CTX_free(OCSP_REQ_CTX *rctx)

{
  if (*(BIO **)(rctx + 0x10) != (BIO *)0x0) {
    BIO_free(*(BIO **)(rctx + 0x10));
  }
  if (*(void **)(rctx + 4) != (void *)0x0) {
    CRYPTO_free(*(void **)(rctx + 4));
  }
  CRYPTO_free(rctx);
  return;
}

