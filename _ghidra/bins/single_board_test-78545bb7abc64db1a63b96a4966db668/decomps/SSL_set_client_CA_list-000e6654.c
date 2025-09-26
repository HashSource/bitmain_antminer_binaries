
void SSL_set_client_CA_list(SSL *s,stack_st_X509_NAME *name_list)

{
  OPENSSL_sk_pop_free(s[3].in_handshake,0x177669);
  s[3].in_handshake = (int)name_list;
  return;
}

