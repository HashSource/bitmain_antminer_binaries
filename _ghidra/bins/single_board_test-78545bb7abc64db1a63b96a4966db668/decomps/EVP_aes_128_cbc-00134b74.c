
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_aes_128_cbc(void)

{
  return (EVP_CIPHER *)&aes_128_cbc;
}

