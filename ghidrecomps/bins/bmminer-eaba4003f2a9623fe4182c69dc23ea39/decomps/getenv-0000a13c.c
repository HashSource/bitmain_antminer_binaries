
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a144. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_00085228)();
  return pcVar1;
}

