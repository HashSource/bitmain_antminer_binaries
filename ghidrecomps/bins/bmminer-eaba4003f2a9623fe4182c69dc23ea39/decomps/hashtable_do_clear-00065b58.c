
void hashtable_do_clear(hashtable_t *hashtable)

{
  hashtable_list *phVar1;
  hashtable_t *hashtable_local;
  pair_t *pair;
  list_t *next;
  list_t *list;
  
  list = (hashtable->list).next;
  while (&hashtable->list != list) {
    phVar1 = list->next;
    json_decref((json_t *)list[2].next);
    jsonp_free(list);
    list = phVar1;
  }
  return;
}

