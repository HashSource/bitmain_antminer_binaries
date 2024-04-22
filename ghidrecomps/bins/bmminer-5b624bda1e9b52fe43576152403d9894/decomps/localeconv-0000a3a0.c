
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lconv * localeconv(void)

{
  lconv *plVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a3a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  plVar1 = (lconv *)(*(code *)PTR_LAB_0005f270)();
  return plVar1;
}

