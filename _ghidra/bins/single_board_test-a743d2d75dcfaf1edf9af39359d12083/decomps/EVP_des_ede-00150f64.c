
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_des_ede(void)

{
  return (EVP_CIPHER *)des_ede_ecb;
}

