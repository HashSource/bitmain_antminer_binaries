
void SSL_set_verify_depth(SSL *s,int depth)

{
  X509_VERIFY_PARAM_set_depth(s->param,depth);
  return;
}

