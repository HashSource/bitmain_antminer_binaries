
void local_sk_X509_NAME_ENTRY_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    CRYPTO_free(*(void **)((int)param_1 + 4));
    CRYPTO_free(param_1);
    return;
  }
  return;
}

