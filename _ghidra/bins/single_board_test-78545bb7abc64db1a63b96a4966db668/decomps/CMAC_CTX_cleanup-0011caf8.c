
void CMAC_CTX_cleanup(CMAC_CTX *ctx)

{
  EVP_CIPHER_CTX_reset(*(undefined4 *)ctx);
  OPENSSL_cleanse(ctx + 0x44,0x20);
  OPENSSL_cleanse(ctx + 4,0x20);
  OPENSSL_cleanse(ctx + 0x24,0x20);
  OPENSSL_cleanse(ctx + 100,0x20);
  *(undefined4 *)(ctx + 0x84) = 0xffffffff;
  return;
}

