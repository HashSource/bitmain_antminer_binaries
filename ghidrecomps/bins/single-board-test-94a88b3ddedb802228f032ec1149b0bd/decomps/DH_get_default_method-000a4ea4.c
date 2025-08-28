
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DH_METHOD * DH_get_default_method(void)

{
  if (default_DH_method != (DH_METHOD *)0x0) {
    return default_DH_method;
  }
  default_DH_method = DH_OpenSSL();
  return default_DH_method;
}

