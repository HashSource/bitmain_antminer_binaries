
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pthread_t pthread_self(void)

{
  pthread_t pVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a754. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pVar1 = (*(code *)PTR_LAB_0005f39c)();
  return pVar1;
}

