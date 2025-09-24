
int BIO_ADDRINFO_sockaddr_size(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 0x10);
  }
  return param_1;
}

