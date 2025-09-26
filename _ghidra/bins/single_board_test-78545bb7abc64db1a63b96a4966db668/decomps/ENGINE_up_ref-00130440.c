
int ENGINE_up_ref(ENGINE *e)

{
  bool bVar1;
  ENGINE *pEVar2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xbe,0x43,"crypto/engine/eng_list.c",0x1af);
    return 0;
  }
  pEVar2 = e + 0x50;
  do {
    ExclusiveAccess(pEVar2);
    bVar1 = (bool)hasExclusiveAccess(pEVar2);
  } while (!bVar1);
  *(int *)pEVar2 = *(int *)pEVar2 + 1;
  return 1;
}

