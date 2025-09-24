
void X509_set_proxy_flag(int param_1)

{
  *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x400;
  return;
}

