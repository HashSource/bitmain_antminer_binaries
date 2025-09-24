
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_md5(void)

{
  return (EVP_MD *)&md5_md;
}

