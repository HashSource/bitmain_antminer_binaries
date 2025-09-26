
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_sha256(void)

{
  return (EVP_MD *)sha256_md;
}

