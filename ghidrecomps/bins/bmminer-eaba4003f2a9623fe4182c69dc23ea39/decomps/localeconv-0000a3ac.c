
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lconv * localeconv(void)

{
  lconv *plVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a3b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  plVar1 = (lconv *)(*(code *)PTR_LAB_000852f8)();
  return plVar1;
}

