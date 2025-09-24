
int SSL_get0_CA_list(int param_1)

{
  if (*(int *)(param_1 + 0x4e0) != 0) {
    return *(int *)(param_1 + 0x4e0);
  }
  return *(int *)(*(int *)(param_1 + 0x4d0) + 0xa4);
}

