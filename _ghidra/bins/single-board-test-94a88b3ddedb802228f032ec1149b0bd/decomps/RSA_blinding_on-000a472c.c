
int RSA_blinding_on(RSA *rsa,BN_CTX *ctx)

{
  BN_BLINDING *pBVar1;
  
  if (rsa->blinding != (BN_BLINDING *)0x0) {
    BN_BLINDING_free(rsa->blinding);
    rsa->blinding = (BN_BLINDING *)0x0;
    rsa->flags = rsa->flags & 0xfffffff7U | 0x80;
  }
  pBVar1 = RSA_setup_blinding(rsa,ctx);
  rsa->blinding = pBVar1;
  if (pBVar1 != (BN_BLINDING *)0x0) {
    pBVar1 = (BN_BLINDING *)0x1;
    rsa->flags = rsa->flags & 0xffffff7fU | 8;
  }
  return (int)pBVar1;
}

