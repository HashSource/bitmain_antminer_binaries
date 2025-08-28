
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA_METHOD * DSA_get_default_method(void)

{
  if (default_DSA_method != (DSA_METHOD *)0x0) {
    return default_DSA_method;
  }
  default_DSA_method = DSA_OpenSSL();
  return default_DSA_method;
}

