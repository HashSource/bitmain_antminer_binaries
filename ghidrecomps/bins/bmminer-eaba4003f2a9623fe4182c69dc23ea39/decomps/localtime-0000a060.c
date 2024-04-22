
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime(time_t *__timer)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR_LAB_000851e0)();
  return ptVar1;
}

