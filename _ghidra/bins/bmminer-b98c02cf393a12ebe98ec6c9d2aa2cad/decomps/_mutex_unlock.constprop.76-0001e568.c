
void _mutex_unlock_constprop_76(pthread_mutex_t *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = pthread_mutex_unlock(param_1);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001e582. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*selective_yield)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _mutex_unlock_noyield_part_48_constprop_77(param_2,param_3);
}

