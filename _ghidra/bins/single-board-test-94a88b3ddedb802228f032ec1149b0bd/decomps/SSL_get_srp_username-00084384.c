
int SSL_get_srp_username(int param_1)

{
  if (*(int *)(param_1 + 0x1a4) != 0) {
    return *(int *)(param_1 + 0x1a4);
  }
  return *(int *)(*(int *)(param_1 + 0xe4) + 0x174);
}

