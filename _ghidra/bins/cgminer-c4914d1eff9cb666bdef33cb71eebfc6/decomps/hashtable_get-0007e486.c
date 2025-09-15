
void * hashtable_get(hashtable_t *hashtable,char *key)

{
  size_t length;
  uint32_t hash_00;
  pair_t *ppVar1;
  json_t *pjVar2;
  char *key_local;
  hashtable_t *hashtable_local;
  pair_t *pair;
  bucket_t *bucket;
  size_t hash;
  
  length = strlen(key);
  hash_00 = hashlittle(key,length,hashtable_seed);
  ppVar1 = hashtable_find_pair(hashtable,
                               hashtable->buckets +
                               (hash_00 & (1 << (hashtable->order & 0xff)) - 1U),key,hash_00);
  if (ppVar1 == (pair_t *)0x0) {
    pjVar2 = (json_t *)0x0;
  }
  else {
    pjVar2 = ppVar1->value;
  }
  return pjVar2;
}

