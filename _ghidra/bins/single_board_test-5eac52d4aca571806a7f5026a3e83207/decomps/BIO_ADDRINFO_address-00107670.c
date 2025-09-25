
int BIO_ADDRINFO_address(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 0x14);
  }
  return param_1;
}

