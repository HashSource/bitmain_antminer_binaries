
void int_engine_module_finish(void)

{
  ENGINE *e;
  
  while (e = (ENGINE *)OPENSSL_sk_pop(initialized_engines), e != (ENGINE *)0x0) {
    ENGINE_finish(e);
  }
  OPENSSL_sk_free(initialized_engines);
  initialized_engines = e;
  return;
}

