
/* WARNING: Unknown calling convention */

void * hashtable_iter_at(hashtable_t *hashtable,char *key)

{
  size_t length;
  uint32_t hash_00;
  size_t hash;
  pair_t *ppVar1;
  pair_t *pair;
  
  length = strlen(key);
  hash_00 = hashlittle(key,length,*DAT_0003e6a0);
  ppVar1 = hashtable_find_pair(hashtable,
                               hashtable->buckets +
                               ((1 << (hashtable->order & 0xff)) - 1U & hash_00),key,hash_00);
  if (ppVar1 != (pair_t *)0x0) {
    ppVar1 = (pair_t *)&ppVar1->list;
  }
  return ppVar1;
}

