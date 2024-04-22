
void hwcrhk_mutex_destroy(int *param_1)

{
  CRYPTO_destroy_dynlockid(*param_1);
  return;
}

