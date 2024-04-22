
void clear_sock(int param_1)

{
  int iVar1;
  ssize_t sVar2;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x2c0));
  if (iVar1 != 0) {
    _mutex_lock_part_1_constprop_16(DAT_00045d64,0x6e5);
  }
  do {
    if (*(int *)(param_1 + 0x24c) == 0) break;
    sVar2 = recv(*(int *)(param_1 + 0x24c),*(void **)(param_1 + 0x250),0x1ffc,0);
  } while (0 < sVar2);
  _mutex_unlock_noyield_constprop_15((pthread_mutex_t *)(param_1 + 0x2c0),DAT_00045d64,0x6ee);
  (*selective_yield)();
  if (*(undefined **)(param_1 + 0x250) != (undefined *)0x0) {
    **(undefined **)(param_1 + 0x250) = 0;
    return;
  }
  return;
}

