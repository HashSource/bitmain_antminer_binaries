
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_000851c4)();
  return pcVar1;
}

