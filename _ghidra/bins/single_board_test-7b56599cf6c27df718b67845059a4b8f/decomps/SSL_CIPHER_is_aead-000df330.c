
uint SSL_CIPHER_is_aead(int param_1)

{
  return (uint)(*(int *)(param_1 + 0x1c) << 0x19) >> 0x1f;
}

