
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DH_METHOD * DH_get_default_method(void)

{
  DH_METHOD **ppDVar1;
  DH_METHOD *pDVar2;
  
  ppDVar1 = DAT_000a4eb8;
  if (*DAT_000a4eb8 != (DH_METHOD *)0x0) {
    return *DAT_000a4eb8;
  }
  pDVar2 = DH_OpenSSL();
  *ppDVar1 = pDVar2;
  return pDVar2;
}

