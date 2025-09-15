
void * hashtable_iter_value(void *iter)

{
  void *iter_local;
  pair_t *pair;
  
  return *(void **)((int)iter + 0xc);
}

