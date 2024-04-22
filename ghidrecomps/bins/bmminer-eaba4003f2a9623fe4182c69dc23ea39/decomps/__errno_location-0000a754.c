
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int * __errno_location(void)

{
  int *piVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a75c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  piVar1 = (int *)(*(code *)PTR_LAB_00085430)();
  return piVar1;
}

