
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_seed_cbc(void)

{
  return (EVP_CIPHER *)&seed_cbc;
}

