
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008438. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_00011730)();
  return iVar1;
}

