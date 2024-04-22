
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000088e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_00025110)();
  return iVar1;
}

