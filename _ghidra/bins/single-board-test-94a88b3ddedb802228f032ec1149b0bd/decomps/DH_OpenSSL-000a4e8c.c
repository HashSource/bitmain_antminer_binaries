
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DH_METHOD * DH_OpenSSL(void)

{
  return (DH_METHOD *)&dh_ossl;
}

