
void inc_dev_status(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75(DAT_0001e630,0x21f4);
  }
  g_max_fan = param_1;
  g_max_temp = param_2;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001e618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*selective_yield)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _mutex_unlock_noyield_part_48_constprop_77(DAT_0001e630,0x21f7);
}

