
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_rc4_hmac_md5(void)

{
  return (EVP_CIPHER *)&r4_hmac_md5_cipher;
}

