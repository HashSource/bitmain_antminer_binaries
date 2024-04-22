
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008fac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR_LAB_000301a4)();
  return sVar1;
}

