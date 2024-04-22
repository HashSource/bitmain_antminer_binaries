
int RAND_set_rand_engine(ENGINE *engine)

{
  ENGINE **ppEVar1;
  int iVar2;
  RAND_METHOD *pRVar3;
  
  if (engine == (ENGINE *)0x0) {
    pRVar3 = (RAND_METHOD *)0x0;
  }
  else {
    iVar2 = ENGINE_init(engine);
    if (iVar2 == 0) {
      return 0;
    }
    pRVar3 = ENGINE_get_RAND(engine);
    if (pRVar3 == (RAND_METHOD *)0x0) {
      ENGINE_finish(engine);
      return 0;
    }
  }
  ppEVar1 = DAT_000ac1c4;
  if (*DAT_000ac1c4 != (ENGINE *)0x0) {
    ENGINE_finish(*DAT_000ac1c4);
  }
  ppEVar1[1] = (ENGINE *)pRVar3;
  *ppEVar1 = engine;
  return 1;
}

