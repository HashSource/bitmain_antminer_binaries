
X509_STORE * SSL_CTX_get_cert_store(SSL_CTX *param_1)

{
  return (X509_STORE *)param_1->sessions;
}

