
void insert_to_bucket(hashtable_t *hashtable,bucket_t *bucket,list_t *list)

{
  int iVar1;
  list_t *list_local;
  bucket_t *bucket_local;
  hashtable_t *hashtable_local;
  
  iVar1 = bucket_is_empty(hashtable,bucket);
  if (iVar1 == 0) {
    list_insert(bucket->first,list);
    bucket->first = list;
  }
  else {
    list_insert(&hashtable->list,list);
    bucket->last = list;
    bucket->first = bucket->last;
  }
  return;
}

