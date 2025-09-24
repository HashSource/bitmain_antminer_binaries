
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_camellia_128_cbc(void)

{
  return (EVP_CIPHER *)&camellia_128_cbc;
}

