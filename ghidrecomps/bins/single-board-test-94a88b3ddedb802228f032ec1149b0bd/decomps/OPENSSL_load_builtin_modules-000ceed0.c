
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OPENSSL_load_builtin_modules(void)

{
  ASN1_add_oid_module();
  ENGINE_add_conf_module();
  EVP_add_alg_module();
  return;
}

