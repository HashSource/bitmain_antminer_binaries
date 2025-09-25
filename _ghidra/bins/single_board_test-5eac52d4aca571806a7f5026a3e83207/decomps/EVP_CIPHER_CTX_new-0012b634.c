
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER_CTX * EVP_CIPHER_CTX_new(void)

{
  EVP_CIPHER_CTX *pEVar1;
  
  pEVar1 = (EVP_CIPHER_CTX *)CRYPTO_zalloc(0x8c,"crypto/evp/evp_enc.c",0x2b);
  return pEVar1;
}

