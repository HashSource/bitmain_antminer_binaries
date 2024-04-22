
int tq_pop(int **param_1,timespec *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  pthread_mutex_t *__mutex;
  
  __mutex = (pthread_mutex_t *)(param_1 + 3);
  iVar1 = pthread_mutex_lock(__mutex);
  if (iVar1 != 0) {
    _mutex_lock_part_1_constprop_16(DAT_000464a0,0x486);
  }
  piVar3 = *param_1;
  if (param_1 == (int **)piVar3) {
    if (param_2 == (timespec *)0x0) {
      iVar1 = pthread_cond_wait((pthread_cond_t *)(param_1 + 10),__mutex);
    }
    else {
      iVar1 = pthread_cond_timedwait((pthread_cond_t *)(param_1 + 10),__mutex,param_2);
    }
    if (iVar1 != 0) {
      iVar1 = 0;
      goto LAB_0004644c;
    }
    piVar3 = *param_1;
    if ((int **)piVar3 == param_1) {
      iVar1 = 0;
      goto LAB_0004644c;
    }
  }
  piVar2 = (int *)piVar3[1];
  iVar4 = *piVar3;
  iVar1 = piVar3[-1];
  *(int **)(iVar4 + 4) = piVar2;
  *piVar2 = iVar4;
  *piVar3 = 0;
  piVar3[1] = 0;
  free(piVar3 + -1);
LAB_0004644c:
  _mutex_unlock_noyield_constprop_15(__mutex,DAT_000464a0,0x4a0);
  (*selective_yield)();
  return iVar1;
}

