
void dtls1_free(int param_1)

{
  ssl3_free();
  dtls1_clear_queues(param_1);
  pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x238));
  pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x240));
  pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244));
  pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x248));
  pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x250));
  CRYPTO_free(*(void **)(param_1 + 0x5c));
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}

