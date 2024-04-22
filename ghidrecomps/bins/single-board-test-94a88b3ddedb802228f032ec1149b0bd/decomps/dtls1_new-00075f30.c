
undefined4 dtls1_new(int param_1)

{
  int iVar1;
  void *__s;
  pqueue p_Var2;
  
  iVar1 = ssl3_new();
  if ((iVar1 == 0) || (__s = CRYPTO_malloc(0x2ec,DAT_00075ffc,0x81), __s == (void *)0x0)) {
    return 0;
  }
  memset(__s,0,0x2ec);
  p_Var2 = pqueue_new();
  *(pqueue *)((int)__s + 0x238) = p_Var2;
  p_Var2 = pqueue_new();
  *(pqueue *)((int)__s + 0x240) = p_Var2;
  p_Var2 = pqueue_new();
  *(pqueue *)((int)__s + 0x244) = p_Var2;
  p_Var2 = pqueue_new();
  *(pqueue *)((int)__s + 0x248) = p_Var2;
  p_Var2 = pqueue_new();
  iVar1 = *(int *)(param_1 + 0x24);
  *(pqueue *)((int)__s + 0x250) = p_Var2;
  if (iVar1 != 0) {
    *(undefined4 *)((int)__s + 0x204) = 0x100;
  }
  *(undefined4 *)((int)__s + 600) = 0;
  *(undefined4 *)((int)__s + 0x25c) = 0;
  if (*(pqueue *)((int)__s + 0x238) != (pqueue)0x0) {
    if ((((*(int *)((int)__s + 0x240) != 0) && (*(int *)((int)__s + 0x244) != 0)) &&
        (*(int *)((int)__s + 0x248) != 0)) && (p_Var2 != (pqueue)0x0)) {
      *(void **)(param_1 + 0x5c) = __s;
      (**(code **)(*(int *)(param_1 + 8) + 8))(param_1);
      return 1;
    }
    pqueue_free(*(pqueue *)((int)__s + 0x238));
  }
  if (*(pqueue *)((int)__s + 0x240) != (pqueue)0x0) {
    pqueue_free(*(pqueue *)((int)__s + 0x240));
  }
  if (*(pqueue *)((int)__s + 0x244) != (pqueue)0x0) {
    pqueue_free(*(pqueue *)((int)__s + 0x244));
  }
  if (*(pqueue *)((int)__s + 0x248) != (pqueue)0x0) {
    pqueue_free(*(pqueue *)((int)__s + 0x248));
  }
  if (*(pqueue *)((int)__s + 0x250) != (pqueue)0x0) {
    pqueue_free(*(pqueue *)((int)__s + 0x250));
  }
  CRYPTO_free(__s);
  return 0;
}

