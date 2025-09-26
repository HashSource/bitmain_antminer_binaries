
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_ecdsa(void)

{
  return (EVP_MD *)&ecdsa_md;
}

