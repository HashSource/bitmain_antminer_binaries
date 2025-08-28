
/* WARNING: Unknown calling convention */

void * hashtable_iter_at(hashtable_t *hashtable,char *key)

{
  size_t length;
  uint32_t hash;
  pair_t *ppVar1;
  
  length = strlen(key);
  hash = hashlittle(key,length,hashtable_seed);
  ppVar1 = hashtable_find_pair(hashtable,
                               hashtable->buckets + ((1 << (hashtable->order & 0xff)) - 1U & hash),
                               key,hash);
  if (ppVar1 != (pair_t *)0x0) {
    ppVar1 = (pair_t *)&ppVar1->list;
  }
  return ppVar1;
}

