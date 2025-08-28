
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_CTX * BN_CTX_new(void)

{
  BN_CTX *pBVar1;
  
  pBVar1 = (BN_CTX *)CRYPTO_malloc(0x2c,"bn_ctx.c",0xd8);
  if (pBVar1 == (BN_CTX *)0x0) {
    ERR_put_error(3,0x6a,0x41,"bn_ctx.c",0xda);
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
    *(undefined4 *)(pBVar1 + 0x20) = 0;
    *(undefined4 *)(pBVar1 + 0x24) = 0;
    *(undefined4 *)(pBVar1 + 0x28) = 0;
  }
  return pBVar1;
}

