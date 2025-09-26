
void RSA_blinding_off(RSA *rsa)

{
  BN_BLINDING_free(rsa->mt_blinding);
  rsa->mt_blinding = (BN_BLINDING *)0x0;
  rsa->_method_mod_n = (BN_MONT_CTX *)((uint)rsa->_method_mod_n & 0xfffffff7 | 0x80);
  return;
}

