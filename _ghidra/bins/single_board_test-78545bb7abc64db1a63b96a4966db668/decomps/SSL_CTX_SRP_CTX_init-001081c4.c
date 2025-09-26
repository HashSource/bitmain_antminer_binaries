
undefined4 SSL_CTX_SRP_CTX_init(int param_1)

{
  if (param_1 != 0) {
    memset((void *)(param_1 + 0x1c0),0,0x40);
    *(undefined4 *)(param_1 + 0x1f8) = 0x400;
    return 1;
  }
  return 0;
}

