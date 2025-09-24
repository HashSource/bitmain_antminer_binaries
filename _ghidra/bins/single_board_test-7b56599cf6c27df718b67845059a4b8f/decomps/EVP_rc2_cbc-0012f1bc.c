
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_rc2_cbc(void)

{
  return (EVP_CIPHER *)&rc2_cbc;
}

