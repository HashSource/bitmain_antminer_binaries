
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008f60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0003018c)();
  return iVar1;
}

