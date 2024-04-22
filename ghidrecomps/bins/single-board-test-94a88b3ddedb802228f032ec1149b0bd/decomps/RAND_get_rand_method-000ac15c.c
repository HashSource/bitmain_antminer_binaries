
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RAND_METHOD * RAND_get_rand_method(void)

{
  ENGINE **ppEVar1;
  RAND_METHOD *pRVar2;
  ENGINE *e;
  
  ppEVar1 = DAT_000ac188;
  pRVar2 = (RAND_METHOD *)DAT_000ac188[1];
  if (pRVar2 == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      pRVar2 = ENGINE_get_RAND(e);
      ppEVar1[1] = (ENGINE *)pRVar2;
      if (pRVar2 != (RAND_METHOD *)0x0) {
        *ppEVar1 = e;
        return pRVar2;
      }
      ENGINE_finish(e);
    }
    pRVar2 = RAND_SSLeay();
    ppEVar1[1] = (ENGINE *)pRVar2;
  }
  return pRVar2;
}

