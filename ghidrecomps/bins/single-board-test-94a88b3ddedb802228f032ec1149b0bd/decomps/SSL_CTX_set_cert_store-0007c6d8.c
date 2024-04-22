
void SSL_CTX_set_cert_store(SSL_CTX *param_1,X509_STORE *param_2)

{
  if (param_1->cert_store != (X509_STORE *)0x0) {
    X509_STORE_free(param_1->cert_store);
  }
  param_1->cert_store = param_2;
  return;
}

