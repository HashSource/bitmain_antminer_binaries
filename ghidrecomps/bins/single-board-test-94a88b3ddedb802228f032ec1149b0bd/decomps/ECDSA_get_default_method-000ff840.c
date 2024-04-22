
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ECDSA_METHOD * ECDSA_get_default_method(void)

{
  ECDSA_METHOD **ppEVar1;
  ECDSA_METHOD *pEVar2;
  
  ppEVar1 = DAT_000ff854;
  if (*DAT_000ff854 != (ECDSA_METHOD *)0x0) {
    return *DAT_000ff854;
  }
  pEVar2 = ECDSA_OpenSSL();
  *ppEVar1 = pEVar2;
  return pEVar2;
}

