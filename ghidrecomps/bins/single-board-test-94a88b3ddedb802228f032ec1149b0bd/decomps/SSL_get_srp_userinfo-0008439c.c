
int SSL_get_srp_userinfo(int param_1)

{
  if (*(int *)(param_1 + 0x1c8) != 0) {
    return *(int *)(param_1 + 0x1c8);
  }
  return *(int *)(*(int *)(param_1 + 0xe4) + 0x198);
}

