
void my_log_curses_part_2(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    pthread_mutex_trylock((pthread_mutex_t *)console_lock);
    _mutex_unlock_noyield_constprop_3(0x29);
    (*selective_yield)();
  }
  _mutex_lock_constprop_4();
  printf("%s%s%s",param_1,param_2,&DAT_00065a20);
  _mutex_unlock_noyield_constprop_3(0x36);
                    /* WARNING: Could not recover jumptable at 0x00040ef4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*selective_yield)();
  return;
}

