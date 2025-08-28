
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EVP_PBE_cleanup(void)

{
  sk_pop_free(pbe_algs,(func *)0xb2dd5);
  pbe_algs = (_STACK *)0x0;
  return;
}

