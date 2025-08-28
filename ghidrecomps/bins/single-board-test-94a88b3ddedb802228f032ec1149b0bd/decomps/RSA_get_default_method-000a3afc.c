
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RSA_METHOD * RSA_get_default_method(void)

{
  if (default_RSA_meth != (RSA_METHOD *)0x0) {
    return default_RSA_meth;
  }
  default_RSA_meth = RSA_PKCS1_SSLeay();
  return default_RSA_meth;
}

