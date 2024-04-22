
undefined pool_tclear(int param_1,undefined *param_2)

{
  undefined uVar1;
  int iVar2;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xbc));
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75(DAT_0001e678,0x321);
  }
  uVar1 = *param_2;
  *param_2 = 0;
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0xbc));
  if (iVar2 == 0) {
    (*selective_yield)();
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  _mutex_unlock_noyield_part_48_constprop_77(DAT_0001e678,0x326);
}

