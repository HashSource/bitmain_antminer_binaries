
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_sha512(void)

{
  return (EVP_MD *)sha512_md;
}

