
int dtls1_new(int param_1)

{
  int iVar1;
  void *ptr;
  pqueue p_Var2;
  
  iVar1 = DTLS_RECORD_LAYER_new(param_1 + 0x650);
  if ((iVar1 == 0) || (iVar1 = ssl3_new(param_1), iVar1 == 0)) {
    return 0;
  }
  ptr = (void *)CRYPTO_zalloc(0x198,"ssl/d1_lib.c",0x4d);
  if (ptr == (void *)0x0) {
    ssl3_free(param_1);
    return 0;
  }
  p_Var2 = pqueue_new();
  *(pqueue *)((int)ptr + 0x110) = p_Var2;
  p_Var2 = pqueue_new();
  iVar1 = *(int *)(param_1 + 0x1c);
  *(pqueue *)((int)ptr + 0x114) = p_Var2;
  if (iVar1 != 0) {
    *(undefined4 *)((int)ptr + 0x100) = 0x100;
  }
  *(undefined4 *)((int)ptr + 0x118) = 0;
  *(undefined4 *)((int)ptr + 0x11c) = 0;
  if (p_Var2 != (pqueue)0x0 && *(pqueue *)((int)ptr + 0x110) != (pqueue)0x0) {
    *(void **)(param_1 + 0x80) = ptr;
    iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  pqueue_free(*(pqueue *)((int)ptr + 0x110));
  pqueue_free(*(pqueue *)((int)ptr + 0x114));
  CRYPTO_free(ptr);
  ssl3_free(param_1);
  return 0;
}

