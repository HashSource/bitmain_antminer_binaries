
void X509_email_free(stack_st_OPENSSL_STRING *sk)

{
  sk_pop_free(&sk->stack,(func *)0x164dc5);
  return;
}

