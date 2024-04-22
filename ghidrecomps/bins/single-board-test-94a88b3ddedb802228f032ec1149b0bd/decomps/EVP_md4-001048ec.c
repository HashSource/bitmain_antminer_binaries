
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_md4(void)

{
  return (EVP_MD *)&md4_md;
}

