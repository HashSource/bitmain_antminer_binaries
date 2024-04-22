
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_RECP_CTX * BN_RECP_CTX_new(void)

{
  BN_RECP_CTX *pBVar1;
  
  pBVar1 = (BN_RECP_CTX *)CRYPTO_malloc(0x34,DAT_000f41dc,0x4b);
  if (pBVar1 != (BN_RECP_CTX *)0x0) {
    BN_init((BIGNUM *)pBVar1);
    BN_init(&pBVar1->Nr);
    pBVar1->num_bits = 0;
    pBVar1->flags = 1;
  }
  return pBVar1;
}

