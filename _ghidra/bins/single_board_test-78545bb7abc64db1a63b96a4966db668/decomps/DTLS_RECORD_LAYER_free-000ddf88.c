
void DTLS_RECORD_LAYER_free(int param_1)

{
  if (*(int *)(param_1 + 0x8e8) != 0) {
    DTLS_RECORD_LAYER_clear();
    pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x8e8) + 0x20));
    pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x8e8) + 0x28));
    pqueue_free(*(pqueue *)(*(int *)(param_1 + 0x8e8) + 0x30));
    CRYPTO_free(*(void **)(param_1 + 0x8e8));
    *(undefined4 *)(param_1 + 0x8e8) = 0;
    return;
  }
  return;
}

