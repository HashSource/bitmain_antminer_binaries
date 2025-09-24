
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_sha1(void)

{
  return (EVP_MD *)&sha1_md;
}

