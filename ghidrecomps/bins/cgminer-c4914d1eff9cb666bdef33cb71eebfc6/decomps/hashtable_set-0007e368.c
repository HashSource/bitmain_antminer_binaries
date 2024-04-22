
int hashtable_set(hashtable_t *hashtable,char *key,json_t *value)

{
  int iVar1;
  size_t sVar2;
  hashtable_list *hash_00;
  pair_t *ppVar3;
  list_t *list;
  hashtable_bucket *phVar4;
  uint uVar5;
  json_t *value_local;
  char *key_local;
  hashtable_t *hashtable_local;
  size_t len;
  pair_t *pair;
  bucket_t *bucket;
  size_t index;
  size_t hash;
  
  if ((hashtable->size >> (hashtable->order & 0xff) != 0) &&
     (iVar1 = hashtable_do_rehash(hashtable), iVar1 != 0)) {
    return -1;
  }
  sVar2 = strlen(key);
  hash_00 = (hashtable_list *)hashlittle(key,sVar2,hashtable_seed);
  uVar5 = hashtable->order;
  phVar4 = hashtable->buckets;
  ppVar3 = hashtable_find_pair(hashtable,phVar4 + ((1 << (uVar5 & 0xff)) - 1U & (uint)hash_00),key,
                               (size_t)hash_00);
  if (ppVar3 == (pair_t *)0x0) {
    sVar2 = strlen(key);
    if (0xffffffe6 < sVar2) {
      return -1;
    }
    list = (list_t *)jsonp_malloc(sVar2 + 0x19);
    if (list == (list_t *)0x0) {
      return -1;
    }
    list[2].prev = hash_00;
    strncpy((char *)(list + 3),key,sVar2 + 1);
    list[2].next = (hashtable_list *)value;
    list_init(list);
    list_init(list + 1);
    insert_to_bucket(hashtable,phVar4 + ((1 << (uVar5 & 0xff)) - 1U & (uint)hash_00),list);
    list_insert(&hashtable->ordered_list,list + 1);
    hashtable->size = hashtable->size + 1;
  }
  else {
    json_decref(ppVar3->value);
    ppVar3->value = value;
  }
  return 0;
}

