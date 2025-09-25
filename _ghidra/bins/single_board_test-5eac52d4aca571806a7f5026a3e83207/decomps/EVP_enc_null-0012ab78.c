
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_enc_null(void)

{
  return (EVP_CIPHER *)&n_cipher;
}

