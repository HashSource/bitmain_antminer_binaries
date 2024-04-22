
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ECDSA_METHOD * ECDSA_OpenSSL(void)

{
  return (ECDSA_METHOD *)&openssl_ecdsa_meth;
}

