
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_sha224(void)

{
  return (EVP_MD *)sha224_md;
}

