
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a42c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_00085320)();
  return iVar1;
}

