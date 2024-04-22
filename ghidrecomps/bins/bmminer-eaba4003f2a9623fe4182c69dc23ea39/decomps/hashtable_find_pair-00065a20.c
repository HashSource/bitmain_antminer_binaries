
pair_t * hashtable_find_pair(hashtable_t *hashtable,bucket_t *bucket,char *key,size_t hash)

{
  int iVar1;
  size_t hash_local;
  char *key_local;
  bucket_t *bucket_local;
  hashtable_t *hashtable_local;
  pair_t *pair;
  list_t *list;
  
  iVar1 = bucket_is_empty(hashtable,bucket);
  if (iVar1 == 0) {
    list = bucket->first;
    while( true ) {
      if ((list[2].prev == (hashtable_list *)hash) &&
         (iVar1 = strcmp((char *)(list + 3),key), iVar1 == 0)) {
        return (pair_t *)list;
      }
      if (bucket->last == list) break;
      list = list->next;
    }
  }
  return (pair_t *)0x0;
}

