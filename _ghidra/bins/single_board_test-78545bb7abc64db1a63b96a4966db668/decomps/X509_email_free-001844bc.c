
void X509_email_free(stack_st_OPENSSL_STRING *sk)

{
  OPENSSL_sk_pop_free(sk,0x18310d);
  return;
}

