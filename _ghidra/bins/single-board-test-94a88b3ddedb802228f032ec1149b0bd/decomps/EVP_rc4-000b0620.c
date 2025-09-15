
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_rc4(void)

{
  return (EVP_CIPHER *)&r4_cipher;
}

