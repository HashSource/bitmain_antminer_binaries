
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int rand(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a5e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0005f328)();
  return iVar1;
}

