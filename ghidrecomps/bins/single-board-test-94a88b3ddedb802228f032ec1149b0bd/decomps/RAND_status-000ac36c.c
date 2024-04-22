
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_status(void)

{
  ENGINE **ppEVar1;
  RAND_METHOD *pRVar2;
  int iVar3;
  ENGINE *e;
  
  ppEVar1 = DAT_000ac3a8;
  pRVar2 = (RAND_METHOD *)DAT_000ac3a8[1];
  if (pRVar2 == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      pRVar2 = ENGINE_get_RAND(e);
      ppEVar1[1] = (ENGINE *)pRVar2;
      if (pRVar2 != (RAND_METHOD *)0x0) {
        *ppEVar1 = e;
        goto LAB_000ac374;
      }
      ENGINE_finish(e);
    }
    pRVar2 = RAND_SSLeay();
    ppEVar1[1] = (ENGINE *)pRVar2;
    if (pRVar2 == (RAND_METHOD *)0x0) {
      return 0;
    }
  }
LAB_000ac374:
  if (pRVar2->status == (_func_3917 *)0x0) {
    return 0;
  }
  iVar3 = (*pRVar2->status)();
  return iVar3;
}

