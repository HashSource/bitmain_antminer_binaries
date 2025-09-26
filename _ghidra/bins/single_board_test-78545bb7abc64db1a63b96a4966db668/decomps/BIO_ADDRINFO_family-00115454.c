
int BIO_ADDRINFO_family(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 4);
  }
  return param_1;
}

