
void hashtable_iter_set(void *iter,json_t *value)

{
  json_t *value_local;
  void *iter_local;
  pair_t *pair;
  
  json_decref(*(json_t **)((int)iter + 0xc));
  *(json_t **)((int)iter + 0xc) = value;
  return;
}

