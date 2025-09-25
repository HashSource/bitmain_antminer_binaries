
int SSL_get_client_ciphers(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      return *(int *)(param_1 + 0xb8);
    }
    param_1 = 0;
  }
  return param_1;
}

