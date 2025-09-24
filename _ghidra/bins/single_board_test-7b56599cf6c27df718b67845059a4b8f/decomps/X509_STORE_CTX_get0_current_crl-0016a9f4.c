
X509_CRL * X509_STORE_CTX_get0_current_crl(X509_STORE_CTX *ctx)

{
  return (X509_CRL *)ctx->current_issuer;
}

