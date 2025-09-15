
void tq_freezethaw(int param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xc));
  if (iVar1 != 0) {
    _mutex_lock_part_1_constprop_16("tq_freezethaw",0x454);
  }
  *(undefined1 *)(param_1 + 8) = param_2;
  pthread_cond_signal((pthread_cond_t *)(param_1 + 0x28));
  _mutex_unlock_noyield_constprop_15((pthread_mutex_t *)(param_1 + 0xc),"tq_freezethaw",0x457);
                    /* WARNING: Could not recover jumptable at 0x00045d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*selective_yield)();
  return;
}

