
undefined4 SSL_CIPHER_get_handshake_digest(int param_1)

{
  if (*(byte *)(param_1 + 0x34) < 0xc) {
    return *(undefined4 *)(ssl_digest_methods + (uint)*(byte *)(param_1 + 0x34) * 4);
  }
  return 0;
}

