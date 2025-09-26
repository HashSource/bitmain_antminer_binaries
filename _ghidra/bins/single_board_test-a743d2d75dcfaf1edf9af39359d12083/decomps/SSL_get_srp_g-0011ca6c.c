
int SSL_get_srp_g(int param_1)

{
  if (*(int *)(param_1 + 0x1ac) != 0) {
    return *(int *)(param_1 + 0x1ac);
  }
  return *(int *)(*(int *)(param_1 + 0xe4) + 0x17c);
}

