
void OPENSSL_sk_new_null(void)

{
  OPENSSL_sk_new_reserve(0);
  return;
}

