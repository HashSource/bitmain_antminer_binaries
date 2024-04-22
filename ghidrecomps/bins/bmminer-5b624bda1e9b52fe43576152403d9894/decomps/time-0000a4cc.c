
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
  time_t tVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a4d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  tVar1 = (*(code *)PTR_LAB_0005f2d0)();
  return tVar1;
}

