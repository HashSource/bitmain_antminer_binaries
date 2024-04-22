
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ECDH_METHOD * ECDH_get_default_method(void)

{
  ECDH_METHOD **ppEVar1;
  ECDH_METHOD *pEVar2;
  
  ppEVar1 = DAT_00100e30;
  if (*DAT_00100e30 != (ECDH_METHOD *)0x0) {
    return *DAT_00100e30;
  }
  pEVar2 = ECDH_OpenSSL();
  *ppEVar1 = pEVar2;
  return pEVar2;
}

