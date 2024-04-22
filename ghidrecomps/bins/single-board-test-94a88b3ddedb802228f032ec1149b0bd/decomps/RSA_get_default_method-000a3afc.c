
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RSA_METHOD * RSA_get_default_method(void)

{
  RSA_METHOD **ppRVar1;
  RSA_METHOD *pRVar2;
  
  ppRVar1 = DAT_000a3b10;
  if (*DAT_000a3b10 != (RSA_METHOD *)0x0) {
    return *DAT_000a3b10;
  }
  pRVar2 = RSA_PKCS1_SSLeay();
  *ppRVar1 = pRVar2;
  return pRVar2;
}

