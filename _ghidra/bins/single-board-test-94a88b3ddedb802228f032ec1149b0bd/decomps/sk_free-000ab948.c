
void sk_free(_STACK *param_1)

{
  if (param_1 != (_STACK *)0x0) {
    if (param_1->data != (char **)0x0) {
      CRYPTO_free(param_1->data);
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

