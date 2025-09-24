
void RAND_add(void *buf,int num,double entropy)

{
  RAND_METHOD *pRVar1;
  
  pRVar1 = RAND_get_rand_method();
  if ((pRVar1 != (RAND_METHOD *)0x0) && (pRVar1->add != (_func_3915 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014c79c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*pRVar1->add)(buf,num,entropy);
    return;
  }
  return;
}

