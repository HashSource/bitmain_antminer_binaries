
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_desx_cbc(void)

{
  return (EVP_CIPHER *)&d_xcbc_cipher;
}

