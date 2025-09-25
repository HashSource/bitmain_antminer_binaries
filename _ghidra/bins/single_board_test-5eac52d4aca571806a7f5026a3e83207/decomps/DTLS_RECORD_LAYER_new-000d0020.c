
undefined4 DTLS_RECORD_LAYER_new(int param_1)

{
  void *ptr;
  pqueue p_Var1;
  
  ptr = CRYPTO_malloc(0x44,"ssl/record/rec_layer_d1.c",0x17);
  if (ptr == (void *)0x0) {
    ERR_put_error(0x14,0x27b,0x41,"ssl/record/rec_layer_d1.c",0x18);
    return 0;
  }
  *(void **)(param_1 + 0x8e8) = ptr;
  p_Var1 = pqueue_new();
  *(pqueue *)((int)ptr + 0x20) = p_Var1;
  p_Var1 = pqueue_new();
  *(pqueue *)((int)ptr + 0x28) = p_Var1;
  p_Var1 = pqueue_new();
  *(pqueue *)((int)ptr + 0x30) = p_Var1;
  if ((*(pqueue *)((int)ptr + 0x20) != (pqueue)0x0) &&
     (p_Var1 != (pqueue)0x0 && *(int *)((int)ptr + 0x28) != 0)) {
    return 1;
  }
  pqueue_free(*(pqueue *)((int)ptr + 0x20));
  pqueue_free(*(pqueue *)((int)ptr + 0x28));
  pqueue_free(*(pqueue *)((int)ptr + 0x30));
  CRYPTO_free(ptr);
  *(undefined4 *)(param_1 + 0x8e8) = 0;
  return 0;
}

