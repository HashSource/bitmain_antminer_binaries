
void mime_hdr_free(void **param_1)

{
  if (*param_1 != (void *)0x0) {
    CRYPTO_free(*param_1);
  }
  if (param_1[1] != (void *)0x0) {
    CRYPTO_free(param_1[1]);
  }
  if ((_STACK *)param_1[2] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)param_1[2],DAT_001271c4);
  }
  CRYPTO_free(param_1);
  return;
}

