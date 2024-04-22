
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int prctl(int __option,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a5d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_000853ac)();
  return iVar1;
}

