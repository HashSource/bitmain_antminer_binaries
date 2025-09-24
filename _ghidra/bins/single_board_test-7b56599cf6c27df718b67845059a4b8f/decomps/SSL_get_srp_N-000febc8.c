
int SSL_get_srp_N(int param_1)

{
  if (*(int *)(param_1 + 0x620) != 0) {
    return *(int *)(param_1 + 0x620);
  }
  return *(int *)(*(int *)(param_1 + 0x4d0) + 0x1d4);
}

