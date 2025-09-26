
void dtls1_free(int param_1)

{
  void *ptr;
  
  DTLS_RECORD_LAYER_free(param_1 + 0x650);
  ssl3_free(param_1);
  ptr = *(void **)(param_1 + 0x80);
  if (ptr != (void *)0x0) {
    dtls1_clear_received_buffer(param_1);
    dtls1_clear_sent_buffer(param_1);
    pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x80) + 0x110));
    pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x80) + 0x114));
    ptr = *(void **)(param_1 + 0x80);
  }
  CRYPTO_free(ptr);
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}

