
void RAND_seed(void *buf,int num)

{
  ENGINE **ppEVar1;
  RAND_METHOD *pRVar2;
  ENGINE *e;
  
  ppEVar1 = DAT_000ac260;
  pRVar2 = (RAND_METHOD *)DAT_000ac260[1];
  if (pRVar2 == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      pRVar2 = ENGINE_get_RAND(e);
      ppEVar1[1] = (ENGINE *)pRVar2;
      if (pRVar2 != (RAND_METHOD *)0x0) {
        *ppEVar1 = e;
        goto LAB_000ac220;
      }
      ENGINE_finish(e);
    }
    pRVar2 = RAND_SSLeay();
    ppEVar1[1] = (ENGINE *)pRVar2;
    if (pRVar2 == (RAND_METHOD *)0x0) {
      return;
    }
  }
LAB_000ac220:
  if (pRVar2->seed != (_func_3912 *)0x0) {
    (*pRVar2->seed)(buf,num);
  }
  return;
}

