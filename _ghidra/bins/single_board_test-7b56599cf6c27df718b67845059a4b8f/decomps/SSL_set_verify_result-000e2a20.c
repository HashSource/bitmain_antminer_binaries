
void SSL_set_verify_result(SSL *ssl,long v)

{
  ssl[3].wbio = (BIO *)v;
  return;
}

