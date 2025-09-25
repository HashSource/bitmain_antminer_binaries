
void EVP_MD_CTX_new(void)

{
  CRYPTO_zalloc(0x18,"crypto/evp/digest.c",0x3e);
  return;
}

