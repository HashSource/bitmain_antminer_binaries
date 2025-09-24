
int SSL_get_srp_g(int param_1)

{
  if (*(int *)(param_1 + 0x624) != 0) {
    return *(int *)(param_1 + 0x624);
  }
  return *(int *)(*(int *)(param_1 + 0x4d0) + 0x1d8);
}

