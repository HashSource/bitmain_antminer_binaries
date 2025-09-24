
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  OPENSSL_sk_pop_free(xptable,0x177c6d);
  xptable = 0;
  return;
}

