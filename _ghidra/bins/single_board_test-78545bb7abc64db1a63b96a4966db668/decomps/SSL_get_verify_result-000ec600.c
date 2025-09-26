
long SSL_get_verify_result(SSL *ssl)

{
  return (long)ssl[3].wbio;
}

