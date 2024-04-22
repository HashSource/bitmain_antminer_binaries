
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OPENSSL_add_all_algorithms_noconf(void)

{
  OPENSSL_cpuid_setup();
  OpenSSL_add_all_ciphers();
  OpenSSL_add_all_digests();
  return;
}

