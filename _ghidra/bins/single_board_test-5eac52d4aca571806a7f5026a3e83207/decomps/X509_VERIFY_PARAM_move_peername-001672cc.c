
void X509_VERIFY_PARAM_move_peername(int param_1,int param_2)

{
  void *pvVar1;
  
  if (param_2 != 0) {
    pvVar1 = *(void **)(param_2 + 0x2c);
    if (pvVar1 != *(void **)(param_1 + 0x2c)) {
      CRYPTO_free(*(void **)(param_1 + 0x2c));
      *(void **)(param_1 + 0x2c) = pvVar1;
    }
    *(undefined4 *)(param_2 + 0x2c) = 0;
    return;
  }
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return;
}

