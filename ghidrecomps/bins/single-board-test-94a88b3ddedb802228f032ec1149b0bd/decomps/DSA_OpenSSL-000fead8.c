
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA_METHOD * DSA_OpenSSL(void)

{
  return (DSA_METHOD *)&openssl_dsa_meth;
}

