
int hashtable_do_rehash(hashtable_t *hashtable)

{
  hashtable_bucket *phVar1;
  int extraout_r1;
  uint uVar2;
  int iVar3;
  hashtable_list *phVar4;
  hashtable_t *hashtable_local;
  size_t index;
  pair_t *pair;
  list_t *next;
  hashtable_bucket *new_buckets;
  size_t new_size;
  size_t new_order;
  size_t i;
  list_t *list;
  
  uVar2 = hashtable->order + 1;
  iVar3 = 1 << (uVar2 & 0xff);
  phVar1 = (hashtable_bucket *)jsonp_malloc(iVar3 << 3);
  if (phVar1 == (hashtable_bucket *)0x0) {
    iVar3 = -1;
  }
  else {
    jsonp_free(hashtable->buckets);
    hashtable->buckets = phVar1;
    hashtable->order = uVar2;
    for (i = 0; i < (uint)(1 << (hashtable->order & 0xff)); i = i + 1) {
      phVar1 = hashtable->buckets;
      phVar1[i].last = &hashtable->list;
      hashtable->buckets[i].first = phVar1[i].last;
    }
    list = (hashtable->list).next;
    list_init(&hashtable->list);
    while (list != &hashtable->list) {
      phVar4 = list->next;
      __aeabi_uidivmod(list[2].prev,iVar3);
      insert_to_bucket(hashtable,hashtable->buckets + extraout_r1,list);
      list = phVar4;
    }
    iVar3 = 0;
  }
  return iVar3;
}

