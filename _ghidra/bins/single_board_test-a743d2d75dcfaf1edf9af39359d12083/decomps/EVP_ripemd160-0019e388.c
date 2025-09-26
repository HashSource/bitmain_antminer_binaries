
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_ripemd160(void)

{
  return (EVP_MD *)&ripemd160_md;
}

