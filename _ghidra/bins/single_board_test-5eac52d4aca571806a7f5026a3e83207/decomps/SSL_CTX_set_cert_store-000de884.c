
void SSL_CTX_set_cert_store(SSL_CTX *param_1,X509_STORE *param_2)

{
  X509_STORE_free((X509_STORE *)param_1->sessions);
  param_1->sessions = (lhash_st_SSL_SESSION *)param_2;
  return;
}

