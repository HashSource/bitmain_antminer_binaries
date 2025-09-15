
int hashtable_do_rehash(hashtable_t *hashtable)

{
  hashtable_bucket *phVar1;
  int extraout_r1;
  hashtable_bucket *phVar2;
  uint uVar3;
  int iVar4;
  hashtable_list *phVar5;
  hashtable_t *hashtable_local;
  size_t index;
  pair_t *pair;
  list_t *next;
  hashtable_bucket *new_buckets;
  size_t new_size;
  size_t new_order;
  size_t i;
  list_t *list;
  
  uVar3 = hashtable->order + 1;
  iVar4 = 1 << (uVar3 & 0xff);
  phVar1 = (hashtable_bucket *)jsonp_malloc(iVar4 << 3);
  if (phVar1 == (hashtable_bucket *)0x0) {
    iVar4 = -1;
  }
  else {
    jsonp_free(hashtable->buckets);
    hashtable->buckets = phVar1;
    hashtable->order = uVar3;
    for (i = 0; i < (uint)(1 << (hashtable->order & 0xff)); i = i + 1) {
      phVar2 = hashtable->buckets;
      phVar1 = hashtable->buckets;
      phVar1[i].last = &hashtable->list;
      phVar2[i].first = phVar1[i].last;
    }
    list = (hashtable->list).next;
    list_init(&hashtable->list);
    while (&hashtable->list != list) {
      phVar5 = list->next;
      __aeabi_uidivmod(list[2].prev,iVar4);
      insert_to_bucket(hashtable,hashtable->buckets + extraout_r1,list);
      list = phVar5;
    }
    iVar4 = 0;
  }
  return iVar4;
}

