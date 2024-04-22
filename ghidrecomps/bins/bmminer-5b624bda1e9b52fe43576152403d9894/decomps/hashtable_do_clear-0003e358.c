
/* WARNING: Unknown calling convention */

void hashtable_do_clear(hashtable_t *hashtable)

{
  hashtable_list *json;
  hashtable_list *phVar1;
  hashtable_list *phVar2;
  list_t *list;
  list_t *next;
  pair_t *pair;
  
  phVar2 = (hashtable->list).next;
  while (phVar2 != &hashtable->list) {
    json = phVar2[1].prev;
    pair = (pair_t *)&phVar2[-1].next;
    phVar2 = phVar2->next;
    if (((json != (hashtable_list *)0x0) &&
        (phVar1 = (hashtable_list *)((int)&json->next[-1].next + 3),
        json->next != (hashtable_list *)0xffffffff)) &&
       (json->next = phVar1, phVar1 == (hashtable_list *)0x0)) {
      json_delete((json_t *)json);
    }
    _jsonp_free(&pair);
  }
  return;
}

