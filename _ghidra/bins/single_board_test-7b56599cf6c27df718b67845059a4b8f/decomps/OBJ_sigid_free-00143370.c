
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OBJ_sigid_free(void)

{
  OPENSSL_sk_pop_free(sig_app,0x1431a5);
  sig_app = 0;
  OPENSSL_sk_free(sigx_app);
  sigx_app = 0;
  return;
}

