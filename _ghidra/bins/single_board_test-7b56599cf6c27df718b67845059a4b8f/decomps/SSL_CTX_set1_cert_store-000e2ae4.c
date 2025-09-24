
void SSL_CTX_set1_cert_store(SSL_CTX *param_1,X509_STORE *param_2)

{
  if (param_2 != (X509_STORE *)0x0) {
    X509_STORE_up_ref(param_2);
  }
  SSL_CTX_set_cert_store(param_1,param_2);
  return;
}

