
void * hashtable_iter_next(hashtable_t *hashtable,void *iter)

{
  void *pvVar1;
  void *iter_local;
  hashtable_t *hashtable_local;
  list_t *list;
  
  if ((hashtable_list *)*(undefined **)((int)iter + 4) == &hashtable->ordered_list) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = *(void **)((int)iter + 4);
  }
  return pvVar1;
}

