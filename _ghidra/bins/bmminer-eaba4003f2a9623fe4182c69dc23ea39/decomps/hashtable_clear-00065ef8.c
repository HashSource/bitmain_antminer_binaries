
void hashtable_clear(hashtable_t *hashtable)

{
  hashtable_bucket *phVar1;
  hashtable_bucket *phVar2;
  hashtable_t *hashtable_local;
  size_t i;
  
  hashtable_do_clear(hashtable);
  for (i = 0; i < (uint)(1 << (hashtable->order & 0xff)); i = i + 1) {
    phVar2 = hashtable->buckets;
    phVar1 = hashtable->buckets;
    phVar1[i].last = &hashtable->list;
    phVar2[i].first = phVar1[i].last;
  }
  list_init(&hashtable->list);
  list_init(&hashtable->ordered_list);
  hashtable->size = 0;
  return;
}

