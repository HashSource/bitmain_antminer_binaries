
void * hashtable_iter_key(void *iter)

{
  void *iter_local;
  pair_t *pair;
  
  return (void *)((int)iter + 0x10);
}

