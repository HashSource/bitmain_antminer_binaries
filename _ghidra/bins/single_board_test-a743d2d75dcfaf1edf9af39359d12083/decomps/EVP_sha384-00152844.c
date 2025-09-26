
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_sha384(void)

{
  return (EVP_MD *)sha384_md;
}

