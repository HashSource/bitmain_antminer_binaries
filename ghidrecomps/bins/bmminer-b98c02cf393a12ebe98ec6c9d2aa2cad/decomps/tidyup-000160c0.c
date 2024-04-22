
void tidyup(int *param_1)

{
  void **ppvVar1;
  int iVar2;
  void **__ptr;
  void **ppvVar3;
  
  iVar2 = pthread_mutex_lock(DAT_00016158);
  if (iVar2 != 0) {
    _mutex_lock_part_3_constprop_27(DAT_0001615c,0x125d);
  }
  bye = 1;
  if (*param_1 != -1) {
    shutdown(*param_1,2);
    close(*param_1);
    *param_1 = -1;
  }
  if (ipaccess != (void *)0x0) {
    free(ipaccess);
    ipaccess = (void *)0x0;
  }
  ppvVar1 = io_head;
  __ptr = io_head;
  if (io_head != (void **)0x0) {
    do {
      ppvVar3 = (void **)__ptr[2];
      free(*(void **)((int)*__ptr + 4));
      free(*__ptr);
      free(__ptr);
      __ptr = ppvVar3;
    } while (ppvVar1 != ppvVar3);
    io_head = (void **)0x0;
  }
  iVar2 = pthread_mutex_unlock(DAT_00016158);
  if (iVar2 != 0) {
    _mutex_unlock_noyield_part_5_constprop_32(DAT_0001615c,0x1272);
  }
                    /* WARNING: Could not recover jumptable at 0x0001613c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*selective_yield)();
  return;
}

