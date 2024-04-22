
void pqueue_free(pqueue pq)

{
  if (pq != (pqueue)0x0) {
    CRYPTO_free(pq);
    return;
  }
  return;
}

