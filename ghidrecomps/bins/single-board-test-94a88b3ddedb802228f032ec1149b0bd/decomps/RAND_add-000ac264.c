
void RAND_add(void *buf,int num,double entropy)

{
  ENGINE **ppEVar1;
  RAND_METHOD *pRVar2;
  ENGINE *e;
  undefined4 in_stack_ffffffe0;
  int in_stack_ffffffe4;
  
  ppEVar1 = DAT_000ac2c0;
  pRVar2 = (RAND_METHOD *)DAT_000ac2c0[1];
  if (pRVar2 == (RAND_METHOD *)0x0) {
    e = ENGINE_get_default_RAND();
    if (e != (ENGINE *)0x0) {
      pRVar2 = ENGINE_get_RAND(e);
      ppEVar1[1] = (ENGINE *)pRVar2;
      if (pRVar2 != (RAND_METHOD *)0x0) {
        *ppEVar1 = e;
        in_stack_ffffffe4 = num;
        goto LAB_000ac278;
      }
      ENGINE_finish(e);
    }
    pRVar2 = RAND_SSLeay();
    ppEVar1[1] = (ENGINE *)pRVar2;
    in_stack_ffffffe4 = num;
    if (pRVar2 == (RAND_METHOD *)0x0) {
      return;
    }
  }
LAB_000ac278:
  if (pRVar2->add != (_func_3915 *)0x0) {
    (*pRVar2->add)(buf,num,(double)CONCAT44(in_stack_ffffffe4,in_stack_ffffffe0));
  }
  return;
}

