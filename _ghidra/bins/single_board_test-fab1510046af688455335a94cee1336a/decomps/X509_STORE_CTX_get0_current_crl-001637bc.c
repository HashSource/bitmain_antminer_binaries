
X509_CRL * X509_STORE_CTX_get0_current_crl(X509_STORE_CTX *ctx)

{
  return ctx->current_crl;
}

