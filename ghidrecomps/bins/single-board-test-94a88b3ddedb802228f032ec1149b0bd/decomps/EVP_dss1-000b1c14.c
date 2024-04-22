
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD * EVP_dss1(void)

{
  return (EVP_MD *)&dss1_md;
}

