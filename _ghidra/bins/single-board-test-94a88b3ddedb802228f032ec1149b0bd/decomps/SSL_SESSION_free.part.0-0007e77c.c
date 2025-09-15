
void SSL_SESSION_free_part_0(void *param_1)

{
  CRYPTO_free_ex_data(3,param_1,(CRYPTO_EX_DATA *)((int)param_1 + 0xc0));
  OPENSSL_cleanse((void *)((int)param_1 + 8),8);
  OPENSSL_cleanse((void *)((int)param_1 + 0x14),0x30);
  OPENSSL_cleanse((void *)((int)param_1 + 0x48),0x20);
  if (*(int *)((int)param_1 + 0x98) != 0) {
    ssl_sess_cert_free();
  }
  if (*(X509 **)((int)param_1 + 0x9c) != (X509 *)0x0) {
    X509_free(*(X509 **)((int)param_1 + 0x9c));
  }
  if (*(_STACK **)((int)param_1 + 0xbc) != (_STACK *)0x0) {
    sk_free(*(_STACK **)((int)param_1 + 0xbc));
  }
  if (*(void **)((int)param_1 + 0xd0) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0xd0));
  }
  if (*(void **)((int)param_1 + 0xe4) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0xe4));
  }
  *(undefined4 *)((int)param_1 + 0xd4) = 0;
  if (*(void **)((int)param_1 + 0xd8) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0xd8));
  }
  *(undefined4 *)((int)param_1 + 0xdc) = 0;
  if (*(void **)((int)param_1 + 0xe0) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0xe0));
  }
  if (*(void **)((int)param_1 + 0x8c) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x8c));
  }
  if (*(void **)((int)param_1 + 0x90) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0x90));
  }
  if (*(void **)((int)param_1 + 0xf0) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 0xf0));
  }
  OPENSSL_cleanse(param_1,0xf4);
  CRYPTO_free(param_1);
  return;
}

