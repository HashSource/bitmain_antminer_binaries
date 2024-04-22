
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
  __sighandler_t p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = (__sighandler_t)(*(code *)PTR_LAB_0005f174)();
  return p_Var1;
}

