
void RAND_seed(void *buf,int num)

{
  RAND_METHOD *pRVar1;
  
  pRVar1 = RAND_get_rand_method();
  if ((pRVar1 != (RAND_METHOD *)0x0) && (pRVar1->seed != (_func_3912 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014c770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*pRVar1->seed)(buf,num);
    return;
  }
  return;
}

