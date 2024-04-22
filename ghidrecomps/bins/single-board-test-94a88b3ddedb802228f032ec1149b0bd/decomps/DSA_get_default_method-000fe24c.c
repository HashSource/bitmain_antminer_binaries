
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA_METHOD * DSA_get_default_method(void)

{
  DSA_METHOD **ppDVar1;
  DSA_METHOD *pDVar2;
  
  ppDVar1 = DAT_000fe260;
  if (*DAT_000fe260 != (DSA_METHOD *)0x0) {
    return *DAT_000fe260;
  }
  pDVar2 = DSA_OpenSSL();
  *ppDVar1 = pDVar2;
  return pDVar2;
}

