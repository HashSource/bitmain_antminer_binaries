
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_status(void)

{
  RAND_METHOD *pRVar1;
  int iVar2;
  
  pRVar1 = RAND_get_rand_method();
  if ((pRVar1 != (RAND_METHOD *)0x0) && (pRVar1->status != (_func_3917 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0014861c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*pRVar1->status)();
    return iVar2;
  }
  return 0;
}

