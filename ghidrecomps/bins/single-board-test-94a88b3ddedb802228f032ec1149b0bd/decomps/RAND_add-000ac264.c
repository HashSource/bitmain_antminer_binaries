
void RAND_add(void *buf,int num,double entropy)

{
  ENGINE *e;
  
  e = funct_ref;
  if (default_RAND_meth == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      default_RAND_meth = ENGINE_get_RAND(e);
      if (default_RAND_meth != (RAND_METHOD *)0x0) goto LAB_000ac278;
      ENGINE_finish(e);
    }
    default_RAND_meth = RAND_SSLeay();
    e = funct_ref;
    if (default_RAND_meth == (RAND_METHOD *)0x0) {
      return;
    }
  }
LAB_000ac278:
  funct_ref = e;
  if (default_RAND_meth->add != (_func_3915 *)0x0) {
    (*default_RAND_meth->add)(buf,num,entropy);
  }
  return;
}

