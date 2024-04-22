
void wake_gws(void)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock(stgd_lock);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75(DAT_0001ec54,0x14ab);
  }
  pthread_cond_signal((pthread_cond_t *)gws_cond);
  iVar1 = pthread_mutex_unlock(stgd_lock);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001ec3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*selective_yield)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _mutex_unlock_noyield_part_48_constprop_77(DAT_0001ec54,0x14ad);
}

