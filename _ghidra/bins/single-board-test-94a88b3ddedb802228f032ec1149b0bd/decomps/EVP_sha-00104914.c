
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_sha(void)

{
  return (EVP_MD *)&sha_md;
}

