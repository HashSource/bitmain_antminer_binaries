
int BIO_ADDRINFO_socktype(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 8);
  }
  return param_1;
}

