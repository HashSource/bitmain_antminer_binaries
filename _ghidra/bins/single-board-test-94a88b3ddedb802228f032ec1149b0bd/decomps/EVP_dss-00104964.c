
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_dss(void)

{
  return (EVP_MD *)&dsa_md;
}

