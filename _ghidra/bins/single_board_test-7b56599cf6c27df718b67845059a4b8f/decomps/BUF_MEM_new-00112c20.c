
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BUF_MEM * BUF_MEM_new(void)

{
  BUF_MEM *pBVar1;
  
  pBVar1 = (BUF_MEM *)CRYPTO_zalloc(0x10,"crypto/buffer/buffer.c",0x23);
  if (pBVar1 == (BUF_MEM *)0x0) {
    ERR_put_error(7,0x65,0x41,"crypto/buffer/buffer.c",0x25);
  }
  return pBVar1;
}

