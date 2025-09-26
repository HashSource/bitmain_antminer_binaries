
stack_st_X509_NAME * SSL_CTX_get_client_CA_list(SSL_CTX *s)

{
  return s->client_CA;
}

