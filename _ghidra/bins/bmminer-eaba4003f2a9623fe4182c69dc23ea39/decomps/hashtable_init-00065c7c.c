
int hashtable_init(hashtable_t *hashtable)

{
  hashtable_bucket *phVar1;
  hashtable_bucket *phVar2;
  int iVar3;
  hashtable_t *hashtable_local;
  size_t i;
  
  hashtable->size = 0;
  hashtable->order = 3;
  phVar1 = (hashtable_bucket *)jsonp_malloc(8 << (hashtable->order & 0xff));
  hashtable->buckets = phVar1;
  if (hashtable->buckets == (hashtable_bucket *)0x0) {
    iVar3 = -1;
  }
  else {
    list_init(&hashtable->list);
    list_init(&hashtable->ordered_list);
    for (i = 0; i < (uint)(1 << (hashtable->order & 0xff)); i = i + 1) {
      phVar2 = hashtable->buckets;
      phVar1 = hashtable->buckets;
      phVar1[i].last = &hashtable->list;
      phVar2[i].first = phVar1[i].last;
    }
    iVar3 = 0;
  }
  return iVar3;
}

