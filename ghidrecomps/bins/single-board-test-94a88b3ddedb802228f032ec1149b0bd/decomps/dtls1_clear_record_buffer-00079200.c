
void dtls1_clear_record_buffer(int param_1)

{
  pitem *item;
  void *ptr;
  
  while (item = pqueue_pop(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x248)), item != (pitem *)0x0) {
    ptr = item->data;
    if (*(int *)((int)ptr + 0x14) != 0) {
      EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)((int)ptr + 0x18));
      EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)ptr + 0x1c));
    }
    if (*(void **)((int)ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x2c));
    }
    if (*(void **)((int)ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x30));
    }
    CRYPTO_free(ptr);
    pitem_free(item);
  }
  return;
}

