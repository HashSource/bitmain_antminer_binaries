
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_load_builtin_engines(void)

{
  OPENSSL_cpuid_setup();
  ENGINE_load_rdrand();
  ENGINE_load_dynamic();
  ENGINE_load_4758cca();
  ENGINE_load_aep();
  ENGINE_load_atalla();
  ENGINE_load_cswift();
  ENGINE_load_chil();
  ENGINE_load_nuron();
  ENGINE_load_sureware();
  ENGINE_load_ubsec();
  ENGINE_load_padlock();
  ENGINE_load_gost();
  ENGINE_register_all_complete();
  return;
}

