
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void RAND_cleanup(void)

{
  ENGINE **ppEVar1;
  ENGINE **ppEVar2;
  RAND_METHOD *pRVar3;
  ENGINE *e;
  
  ppEVar1 = DAT_000ac210;
  pRVar3 = (RAND_METHOD *)DAT_000ac210[1];
  if (pRVar3 == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      pRVar3 = ENGINE_get_RAND(e);
      ppEVar1[1] = (ENGINE *)pRVar3;
      if (pRVar3 != (RAND_METHOD *)0x0) {
        *ppEVar1 = e;
        goto LAB_000ac1d0;
      }
      ENGINE_finish(e);
    }
    pRVar3 = RAND_SSLeay();
    ppEVar1[1] = (ENGINE *)pRVar3;
    if (pRVar3 == (RAND_METHOD *)0x0) goto LAB_000ac1d6;
  }
LAB_000ac1d0:
  if (pRVar3->cleanup != (_func_3914 *)0x0) {
    (*pRVar3->cleanup)();
  }
LAB_000ac1d6:
  ppEVar2 = DAT_000ac210;
  if (*ppEVar1 != (ENGINE *)0x0) {
    ENGINE_finish(*ppEVar1);
    *ppEVar2 = (ENGINE *)0x0;
  }
  ppEVar1[1] = (ENGINE *)0x0;
  return;
}

