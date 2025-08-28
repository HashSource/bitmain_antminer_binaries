
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

UI_METHOD * UI_get_default_method(void)

{
  if (default_UI_meth != (UI_METHOD *)0x0) {
    return default_UI_meth;
  }
  default_UI_meth = UI_OpenSSL();
  return default_UI_meth;
}

