
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_cast5_cbc(void)

{
  return (EVP_CIPHER *)&cast5_cbc;
}

