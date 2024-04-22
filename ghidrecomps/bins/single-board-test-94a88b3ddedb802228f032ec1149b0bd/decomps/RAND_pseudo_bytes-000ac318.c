
int RAND_pseudo_bytes(uchar *buf,int num)

{
  ENGINE **ppEVar1;
  RAND_METHOD *pRVar2;
  int iVar3;
  ENGINE *e;
  
  ppEVar1 = DAT_000ac368;
  pRVar2 = (RAND_METHOD *)DAT_000ac368[1];
  if (pRVar2 == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      pRVar2 = ENGINE_get_RAND(e);
      ppEVar1[1] = (ENGINE *)pRVar2;
      if (pRVar2 != (RAND_METHOD *)0x0) {
        *ppEVar1 = e;
        goto LAB_000ac324;
      }
      ENGINE_finish(e);
    }
    pRVar2 = RAND_SSLeay();
    ppEVar1[1] = (ENGINE *)pRVar2;
    if (pRVar2 == (RAND_METHOD *)0x0) {
      return -1;
    }
  }
LAB_000ac324:
  if (pRVar2->pseudorand == (_func_3916 *)0x0) {
    return -1;
  }
  iVar3 = (*pRVar2->pseudorand)(buf,num);
  return iVar3;
}

