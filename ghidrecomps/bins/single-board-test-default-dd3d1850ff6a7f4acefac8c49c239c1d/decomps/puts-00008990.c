
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0002514c)();
  return iVar1;
}

