
int bucket_is_empty(hashtable_t *hashtable,bucket_t *bucket)

{
  int iVar1;
  bucket_t *bucket_local;
  hashtable_t *hashtable_local;
  
  if ((bucket->first == &hashtable->list) && (bucket->first == bucket->last)) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

