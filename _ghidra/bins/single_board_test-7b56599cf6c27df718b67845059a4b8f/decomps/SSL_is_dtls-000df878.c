
uint SSL_is_dtls(int param_1)

{
  return (uint)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c) >> 0x1f;
}

