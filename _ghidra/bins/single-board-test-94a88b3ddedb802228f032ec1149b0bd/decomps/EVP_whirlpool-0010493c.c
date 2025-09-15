
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_whirlpool(void)

{
  return (EVP_MD *)&whirlpool_md;
}

