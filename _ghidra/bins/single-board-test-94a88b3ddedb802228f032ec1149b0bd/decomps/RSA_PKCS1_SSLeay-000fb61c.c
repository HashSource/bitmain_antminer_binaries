
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RSA_METHOD * RSA_PKCS1_SSLeay(void)

{
  return (RSA_METHOD *)&rsa_pkcs1_eay_meth;
}

