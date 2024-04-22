
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a10c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0005f19c)();
  return pcVar1;
}

