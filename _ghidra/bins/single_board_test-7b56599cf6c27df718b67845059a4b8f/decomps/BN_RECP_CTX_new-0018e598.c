
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_RECP_CTX * BN_RECP_CTX_new(void)

{
  BN_RECP_CTX *pBVar1;
  
  pBVar1 = (BN_RECP_CTX *)CRYPTO_zalloc(0x34,"crypto/bn/bn_recp.c",0x18);
  if (pBVar1 == (BN_RECP_CTX *)0x0) {
    ERR_put_error(3,0x96,0x41,"crypto/bn/bn_recp.c",0x19);
  }
  else {
    bn_init();
    bn_init(&pBVar1->Nr);
    pBVar1->flags = 1;
  }
  return pBVar1;
}

