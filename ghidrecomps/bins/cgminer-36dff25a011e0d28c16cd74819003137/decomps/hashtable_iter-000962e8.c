
void * hashtable_iter(hashtable_t *hashtable)

{
  void *pvVar1;
  hashtable_t *hashtable_local;
  
  pvVar1 = hashtable_iter_next(hashtable,&hashtable->ordered_list);
  return pvVar1;
}

