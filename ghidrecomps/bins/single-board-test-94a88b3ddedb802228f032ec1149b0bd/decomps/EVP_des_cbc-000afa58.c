
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_des_cbc(void)

{
  return (EVP_CIPHER *)&des_cbc;
}

