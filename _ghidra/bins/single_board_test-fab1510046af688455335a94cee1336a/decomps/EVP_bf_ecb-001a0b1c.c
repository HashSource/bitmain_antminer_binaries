
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_bf_ecb(void)

{
  return (EVP_CIPHER *)bf_ecb;
}

