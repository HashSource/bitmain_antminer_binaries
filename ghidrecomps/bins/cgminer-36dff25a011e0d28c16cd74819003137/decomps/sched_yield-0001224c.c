
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_yield(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00012254. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_000c00fc)();
  return iVar1;
}

