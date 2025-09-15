
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RAND_METHOD * RAND_get_rand_method(void)

{
  ENGINE *e;
  
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) {
        funct_ref = e;
        return default_RAND_meth;
      }
      ENGINE_finish(e);
    }
    default_RAND_meth = RAND_SSLeay();
  }
  return default_RAND_meth;
}

