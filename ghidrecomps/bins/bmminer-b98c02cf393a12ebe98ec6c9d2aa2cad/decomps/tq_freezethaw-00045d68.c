
void tq_freezethaw(int param_1,undefined param_2)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xc));
  if (iVar1 != 0) {
    _mutex_lock_part_1_constprop_16(DAT_00045dac,0x454);
  }
  *(undefined *)(param_1 + 8) = param_2;
  pthread_cond_signal((pthread_cond_t *)(param_1 + 0x28));
  _mutex_unlock_noyield_constprop_15((pthread_mutex_t *)(param_1 + 0xc),DAT_00045dac,0x457);
                    /* WARNING: Could not recover jumptable at 0x00045d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*selective_yield)();
  return;
}

