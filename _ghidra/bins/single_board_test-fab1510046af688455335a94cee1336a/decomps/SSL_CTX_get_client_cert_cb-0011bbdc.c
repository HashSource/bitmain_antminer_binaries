
int SSL_CTX_get_client_cert_cb(SSL *ssl,X509 **x509,EVP_PKEY **pkey)

{
  return (int)ssl->cipher_list;
}

