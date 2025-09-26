
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void RAND_cleanup(void)

{
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_0014ce74;
      ENGINE_finish(e);
    }
    default_RAND_meth = RAND_SSLeay();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) goto LAB_0014ce7a;
  }
LAB_0014ce74:
  funct_ref = e;
  if (default_RAND_meth->cleanup != (_func_3914 *)0x0) {
    (*default_RAND_meth->cleanup)();
  }
LAB_0014ce7a:
  if (funct_ref != (ENGINE *)0x0) {
    ENGINE_finish(funct_ref);
    funct_ref = (ENGINE *)0x0;
  }
  default_RAND_meth = (RAND_METHOD *)0x0;
  return;
}

