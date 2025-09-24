
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_MONT_CTX * BN_MONT_CTX_new(void)

{
  BN_MONT_CTX *ctx;
  
  ctx = (BN_MONT_CTX *)CRYPTO_malloc(0x4c,"crypto/bn/bn_mont.c",0xe8);
  if (ctx == (BN_MONT_CTX *)0x0) {
    ERR_put_error(3,0x95,0x41,"crypto/bn/bn_mont.c",0xe9);
  }
  else {
    BN_MONT_CTX_init(ctx);
    ctx->flags = 1;
  }
  return ctx;
}

