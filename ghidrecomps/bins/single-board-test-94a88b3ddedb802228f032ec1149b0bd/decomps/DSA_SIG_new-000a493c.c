
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA_SIG * DSA_SIG_new(void)

{
  DSA_SIG *pDVar1;
  
  pDVar1 = (DSA_SIG *)CRYPTO_malloc(8,DAT_000a4954,0x5d);
  if (pDVar1 != (DSA_SIG *)0x0) {
    pDVar1->r = (BIGNUM *)0x0;
    pDVar1->s = (BIGNUM *)0x0;
  }
  return pDVar1;
}

