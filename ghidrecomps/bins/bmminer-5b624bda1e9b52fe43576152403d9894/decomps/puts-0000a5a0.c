
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a5a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0005f314)();
  return iVar1;
}

