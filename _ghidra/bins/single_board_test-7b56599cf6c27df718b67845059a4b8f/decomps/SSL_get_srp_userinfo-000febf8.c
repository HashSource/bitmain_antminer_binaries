
int SSL_get_srp_userinfo(int param_1)

{
  if (*(int *)(param_1 + 0x640) != 0) {
    return *(int *)(param_1 + 0x640);
  }
  return *(int *)(*(int *)(param_1 + 0x4d0) + 500);
}

