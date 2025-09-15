
void X509_STORE_CTX_set_chain(X509_STORE_CTX *c,stack_st_X509 *sk)

{
  c->untrusted = sk;
  return;
}

