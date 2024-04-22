
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ECDH_METHOD * ECDH_OpenSSL(void)

{
  return (ECDH_METHOD *)&openssl_ecdh_meth;
}

