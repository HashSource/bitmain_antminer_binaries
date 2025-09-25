
void SSL_set0_rbio(int param_1,undefined4 param_2)

{
  BIO_free_all(*(BIO **)(param_1 + 8));
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

