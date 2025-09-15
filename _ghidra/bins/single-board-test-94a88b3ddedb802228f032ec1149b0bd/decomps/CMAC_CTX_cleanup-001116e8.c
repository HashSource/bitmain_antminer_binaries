
void CMAC_CTX_cleanup(CMAC_CTX *ctx)

{
  EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)ctx);
  OPENSSL_cleanse(ctx + 0xcc,0x20);
  OPENSSL_cleanse(ctx + 0x8c,0x20);
  OPENSSL_cleanse(ctx + 0xac,0x20);
  OPENSSL_cleanse(ctx + 0xec,0x20);
  *(undefined4 *)(ctx + 0x10c) = 0xffffffff;
  return;
}

