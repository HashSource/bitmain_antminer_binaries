
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_CTX * BN_CTX_new(void)

{
  BN_CTX *pBVar1;
  
  pBVar1 = (BN_CTX *)CRYPTO_zalloc(0x30,"crypto/bn/bn_ctx.c",0x8a);
  if (pBVar1 == (BN_CTX *)0x0) {
    ERR_put_error(3,0x6a,0x41,"crypto/bn/bn_ctx.c",0x8b);
  }
  else {
    *(undefined4 *)(pBVar1 + 8) = 0;
    *(undefined4 *)(pBVar1 + 4) = 0;
    *(undefined4 *)pBVar1 = 0;
    *(undefined4 *)(pBVar1 + 0x10) = 0;
    *(undefined4 *)(pBVar1 + 0xc) = 0;
    *(undefined4 *)(pBVar1 + 0x14) = 0;
    *(undefined4 *)(pBVar1 + 0x1c) = 0;
    *(undefined4 *)(pBVar1 + 0x18) = 0;
  }
  return pBVar1;
}

