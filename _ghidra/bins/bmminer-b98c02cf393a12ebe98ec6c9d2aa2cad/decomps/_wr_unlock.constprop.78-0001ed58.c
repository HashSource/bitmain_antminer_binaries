
void _wr_unlock_constprop_78(pthread_rwlock_t *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = pthread_rwlock_unlock(param_1);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001ed72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*selective_yield)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(param_2,param_3);
}

