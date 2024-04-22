
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER_CTX * EVP_CIPHER_CTX_new(void)

{
  EVP_CIPHER_CTX *__s;
  
  __s = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,DAT_000aeb14,0x58);
  if (__s != (EVP_CIPHER_CTX *)0x0) {
    memset(__s,0,0x8c);
  }
  return __s;
}

