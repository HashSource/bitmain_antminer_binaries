
void SSL_CTX_set_next_protos_advertised_cb(SSL_CTX *s,cb *cb,void *arg)

{
  s[1].cipher_list_by_id = (stack_st_SSL_CIPHER *)cb;
  s[1].cert_store = (x509_store_st *)arg;
  return;
}

