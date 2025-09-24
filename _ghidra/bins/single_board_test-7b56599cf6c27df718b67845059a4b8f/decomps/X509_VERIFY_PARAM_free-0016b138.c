
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param)

{
  if (param != (X509_VERIFY_PARAM *)0x0) {
    OPENSSL_sk_pop_free(param[1].name,0x17fc45);
    OPENSSL_sk_pop_free(param[1].check_time,0x16b129);
    CRYPTO_free((void *)param[1].flags);
    CRYPTO_free((void *)param[1].purpose);
    CRYPTO_free((void *)param[1].depth);
    CRYPTO_free(param);
    return;
  }
  return;
}

