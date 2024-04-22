
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lconv * localeconv(void)

{
  lconv *plVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  plVar1 = (lconv *)(*(code *)PTR_LAB_000354fc)();
  return plVar1;
}

