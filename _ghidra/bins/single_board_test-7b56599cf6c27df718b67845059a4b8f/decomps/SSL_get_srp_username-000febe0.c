
int SSL_get_srp_username(int param_1)

{
  if (*(int *)(param_1 + 0x61c) != 0) {
    return *(int *)(param_1 + 0x61c);
  }
  return *(int *)(*(int *)(param_1 + 0x4d0) + 0x1d0);
}

