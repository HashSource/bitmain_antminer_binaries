
void mime_hdr_free(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    CRYPTO_free((void *)*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    CRYPTO_free((void *)param_1[1]);
  }
  if ((_STACK *)param_1[2] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)param_1[2],(func *)0x1271c9);
  }
  CRYPTO_free(param_1);
  return;
}

