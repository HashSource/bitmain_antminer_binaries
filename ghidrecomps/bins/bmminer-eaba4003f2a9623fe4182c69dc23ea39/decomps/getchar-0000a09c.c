
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getchar(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a0a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_000851f4)();
  return iVar1;
}

