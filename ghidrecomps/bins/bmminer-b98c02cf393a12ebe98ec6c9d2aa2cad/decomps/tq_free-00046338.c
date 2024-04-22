
void tq_free(int **param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  int **ppiVar3;
  int *piVar4;
  
  if (param_1 != (int **)0x0) {
    ppiVar3 = (int **)**param_1;
    ppiVar2 = (int **)*param_1;
    while (ppiVar1 = ppiVar3, param_1 != ppiVar2) {
      piVar4 = ppiVar2[1];
      ppiVar1[1] = piVar4;
      *piVar4 = (int)ppiVar1;
      free(ppiVar2 + -1);
      ppiVar3 = (int **)*ppiVar1;
      ppiVar2 = ppiVar1;
    }
    pthread_cond_destroy((pthread_cond_t *)(param_1 + 10));
    pthread_mutex_destroy((pthread_mutex_t *)(param_1 + 3));
                    /* WARNING: Could not recover jumptable at 0x00012060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_LAB_0007ce68)(param_1);
    return;
  }
  return;
}

