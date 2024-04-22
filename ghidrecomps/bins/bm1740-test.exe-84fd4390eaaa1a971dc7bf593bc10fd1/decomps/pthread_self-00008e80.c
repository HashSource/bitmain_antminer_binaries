
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pthread_t pthread_self(void)

{
  pthread_t pVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008e88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pVar1 = (*(code *)PTR_LAB_00030144)();
  return pVar1;
}

