
void RSA_blinding_off(RSA *rsa)

{
  if (rsa->blinding != (BN_BLINDING *)0x0) {
    BN_BLINDING_free(rsa->blinding);
    rsa->blinding = (BN_BLINDING *)0x0;
  }
  rsa->flags = rsa->flags & 0xfffffff7U | 0x80;
  return;
}

