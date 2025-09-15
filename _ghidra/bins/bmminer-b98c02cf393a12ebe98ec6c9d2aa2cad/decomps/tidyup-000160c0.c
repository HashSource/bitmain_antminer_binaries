
void tidyup(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *__ptr;
  int *piVar3;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)quit_restart_lock);
  if (iVar2 != 0) {
    _mutex_lock_part_3_constprop_27("tidyup",0x125d);
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
  piVar1 = io_head;
  __ptr = io_head;
  if (io_head != (int *)0x0) {
    do {
      piVar3 = (int *)__ptr[2];
      free(*(void **)(*__ptr + 4));
      free((void *)*__ptr);
      free(__ptr);
      __ptr = piVar3;
    } while (piVar1 != piVar3);
    io_head = (int *)0x0;
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield_part_5_constprop_32("tidyup",0x1272);
  }
                    /* WARNING: Could not recover jumptable at 0x0001613c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*selective_yield)();
  return;
}

