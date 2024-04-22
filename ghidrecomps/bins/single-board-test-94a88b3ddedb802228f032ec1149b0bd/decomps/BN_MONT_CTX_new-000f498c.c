
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_MONT_CTX * BN_MONT_CTX_new(void)

{
  BN_MONT_CTX *pBVar1;
  
  pBVar1 = (BN_MONT_CTX *)CRYPTO_malloc(0x4c,DAT_000f49c4,0x155);
  if (pBVar1 != (BN_MONT_CTX *)0x0) {
    pBVar1->ri = 0;
    BN_init(&pBVar1->RR);
    BN_init(&pBVar1->N);
    BN_init(&pBVar1->Ni);
    pBVar1->n0[1] = 0;
    pBVar1->n0[0] = 0;
    pBVar1->flags = 1;
  }
  return pBVar1;
}

