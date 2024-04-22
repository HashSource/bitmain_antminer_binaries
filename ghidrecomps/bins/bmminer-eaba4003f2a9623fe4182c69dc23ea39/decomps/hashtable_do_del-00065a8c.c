
int hashtable_do_del(hashtable_t *hashtable,char *key,size_t hash)

{
  pair_t *list;
  bucket_t *bucket_00;
  int iVar1;
  size_t hash_local;
  char *key_local;
  hashtable_t *hashtable_local;
  pair_t *pair;
  bucket_t *bucket;
  size_t index;
  
  bucket_00 = hashtable->buckets + (hash & (1 << (hashtable->order & 0xff)) - 1U);
  list = hashtable_find_pair(hashtable,bucket_00,key,hash);
  if (list == (pair_t *)0x0) {
    iVar1 = -1;
  }
  else {
    if ((list == (pair_t *)bucket_00->first) && (list == (pair_t *)bucket_00->last)) {
      bucket_00->last = &hashtable->list;
      bucket_00->first = bucket_00->last;
    }
    else if (list == (pair_t *)bucket_00->first) {
      bucket_00->first = (list->list).next;
    }
    else if (list == (pair_t *)bucket_00->last) {
      bucket_00->last = (list->list).prev;
    }
    list_remove(&list->list);
    list_remove(&list->ordered_list);
    json_decref(list->value);
    jsonp_free(list);
    hashtable->size = hashtable->size - 1;
    iVar1 = 0;
  }
  return iVar1;
}

