
bool tq_push(int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 *__ptr;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  __ptr = (undefined4 *)_cgcalloc(1,0xc,"util.c",DAT_00046418,0x469);
  puVar4 = __ptr + 1;
  *__ptr = param_2;
  __ptr[1] = puVar4;
  __ptr[2] = puVar4;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xc));
  if (iVar2 != 0) {
    _mutex_lock_part_1_constprop_16(DAT_00046418,0x46d);
  }
  bVar1 = *(char *)(param_1 + 8) != '\0';
  if (bVar1) {
    free(__ptr);
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 4);
    *(undefined4 **)(param_1 + 4) = puVar4;
    __ptr[1] = param_1;
    __ptr[2] = puVar3;
    *puVar3 = puVar4;
  }
  pthread_cond_signal((pthread_cond_t *)(param_1 + 0x28));
  _mutex_unlock_noyield_constprop_15((pthread_mutex_t *)(param_1 + 0xc),DAT_00046418,0x47a);
  (*selective_yield)();
  return !bVar1;
}

