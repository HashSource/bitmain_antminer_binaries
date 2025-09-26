
void X509_STORE_CTX_free(X509_STORE_CTX *ctx)

{
  if (ctx != (X509_STORE_CTX *)0x0) {
    X509_STORE_CTX_cleanup(ctx);
    CRYPTO_free(ctx);
    return;
  }
  return;
}

