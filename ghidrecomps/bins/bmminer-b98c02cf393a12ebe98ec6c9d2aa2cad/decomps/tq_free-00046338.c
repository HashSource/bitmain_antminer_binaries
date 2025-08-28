
void tq_free(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) {
    piVar3 = (int *)*(int *)*param_1;
    piVar2 = (int *)*param_1;
    while (piVar1 = piVar3, param_1 != piVar2) {
      piVar3 = (int *)piVar2[1];
      piVar1[1] = (int)piVar3;
      *piVar3 = (int)piVar1;
      free(piVar2 + -1);
      piVar3 = (int *)*piVar1;
      piVar2 = piVar1;
    }
    pthread_cond_destroy((pthread_cond_t *)(param_1 + 10));
    pthread_mutex_destroy((pthread_mutex_t *)(param_1 + 3));
    (*(code *)(undefined *)0x0)(param_1);
    return;
  }
  return;
}

