
void cca_ex_free(undefined4 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    CRYPTO_free(param_2);
    return;
  }
  return;
}

