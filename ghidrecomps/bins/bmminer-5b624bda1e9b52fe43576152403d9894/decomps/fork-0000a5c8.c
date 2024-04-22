
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t fork(void)

{
  __pid_t _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a5d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (*(code *)PTR_LAB_0005f320)();
  return _Var1;
}

