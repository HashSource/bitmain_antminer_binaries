
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_md_null(void)

{
  return (EVP_MD *)&null_md;
}

