
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_TRUST_cleanup(void)

{
  OPENSSL_sk_pop_free(trtable,0x1c68f5);
  trtable = 0;
  return;
}

