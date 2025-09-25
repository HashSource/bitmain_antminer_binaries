
undefined4 file_close(int *param_1)

{
  if (*param_1 == 2) {
    OPENSSL_DIR_end(param_1 + 3);
  }
  else {
    BIO_free_all((BIO *)param_1[3]);
  }
  if (*param_1 == 2) {
    CRYPTO_free((void *)param_1[5]);
  }
  else if (param_1[4] != 0) {
    (**(code **)(param_1[4] + 0xc))(param_1 + 5);
    param_1[5] = 0;
    param_1[4] = 0;
  }
  CRYPTO_free(param_1);
  return 1;
}

