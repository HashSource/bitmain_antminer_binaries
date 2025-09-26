
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SSL_load_error_strings(void)

{
  ERR_load_crypto_strings();
  ERR_load_SSL_strings();
  return;
}

