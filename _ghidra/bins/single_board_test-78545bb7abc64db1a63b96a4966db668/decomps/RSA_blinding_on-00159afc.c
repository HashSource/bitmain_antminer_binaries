
int RSA_blinding_on(RSA *rsa,BN_CTX *ctx)

{
  BN_BLINDING *pBVar1;
  
  if (rsa->mt_blinding != (BN_BLINDING *)0x0) {
    RSA_blinding_off(rsa);
  }
  pBVar1 = RSA_setup_blinding(rsa,ctx);
  rsa->mt_blinding = pBVar1;
  if (pBVar1 != (BN_BLINDING *)0x0) {
    pBVar1 = (BN_BLINDING *)0x1;
    rsa->_method_mod_n = (BN_MONT_CTX *)((uint)rsa->_method_mod_n & 0xffffff7f | 8);
  }
  return (int)pBVar1;
}

