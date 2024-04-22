
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

UI_METHOD * UI_get_default_method(void)

{
  UI_METHOD **ppUVar1;
  UI_METHOD *pUVar2;
  
  ppUVar1 = DAT_000d4c9c;
  if (*DAT_000d4c9c != (UI_METHOD *)0x0) {
    return *DAT_000d4c9c;
  }
  pUVar2 = UI_OpenSSL();
  *ppUVar1 = pUVar2;
  return pUVar2;
}

