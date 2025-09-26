
int RAND_set_rand_engine(ENGINE *engine)

{
  int iVar1;
  RAND_METHOD *pRVar2;
  
  if (engine == (ENGINE *)0x0) {
    pRVar2 = (RAND_METHOD *)0x0;
  }
  else {
    iVar1 = ENGINE_init(engine);
    if (iVar1 == 0) {
      return 0;
    }
    pRVar2 = ENGINE_get_RAND(engine);
    if (pRVar2 == (RAND_METHOD *)0x0) {
      ENGINE_finish(engine);
      return 0;
    }
  }
  if (funct_ref != (ENGINE *)0x0) {
    ENGINE_finish(funct_ref);
  }
  default_RAND_meth = pRVar2;
  funct_ref = engine;
  return 1;
}

