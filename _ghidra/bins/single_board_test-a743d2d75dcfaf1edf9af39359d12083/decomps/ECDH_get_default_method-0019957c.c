
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ECDH_METHOD * ECDH_get_default_method(void)

{
  if (default_ECDH_method != (ECDH_METHOD *)0x0) {
    return default_ECDH_method;
  }
  default_ECDH_method = ECDH_OpenSSL();
  return default_ECDH_method;
}

