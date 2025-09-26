
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ECDSA_METHOD * ECDSA_get_default_method(void)

{
  if (default_ECDSA_method != (ECDSA_METHOD *)0x0) {
    return default_ECDSA_method;
  }
  default_ECDSA_method = ECDSA_OpenSSL();
  return default_ECDSA_method;
}

