
/* WARNING: Unknown calling convention */

int hashtable_del(hashtable_t *hashtable,char *key)

{
  size_t length;
  uint32_t hash;
  pair_t *ptr;
  json_t *json;
  hashtable_list *phVar1;
  size_t sVar2;
  pair_t *ppVar3;
  hashtable_list *phVar4;
  size_t *psVar5;
  hashtable_bucket *phVar6;
  uint uVar7;
  bucket_t *bucket;
  bucket_t *bucket_00;
  bool bVar8;
  
  length = strlen(key);
  hash = hashlittle(key,length,hashtable_seed);
  phVar6 = hashtable->buckets;
  uVar7 = (1 << (hashtable->order & 0xff)) - 1U & hash;
  bucket_00 = phVar6 + uVar7;
  ptr = hashtable_find_pair(hashtable,bucket_00,key,hash);
  if (ptr == (pair_t *)0x0) {
    return -1;
  }
  ppVar3 = (pair_t *)bucket_00->last;
  if (ptr == (pair_t *)phVar6[uVar7].first) {
    if (ptr != ppVar3) {
      phVar1 = (ptr->list).next;
    }
    else {
      phVar1 = &hashtable->list;
    }
    if (ptr == ppVar3) {
      bucket_00->last = phVar1;
    }
    phVar6[uVar7].first = phVar1;
  }
  else {
    bVar8 = ptr == ppVar3;
    if (bVar8) {
      ppVar3 = (pair_t *)(ptr->list).prev;
    }
    if (bVar8) {
      bucket_00->last = &ppVar3->list;
    }
  }
  phVar4 = (ptr->list).prev;
  json = ptr->value;
  phVar4->next = (ptr->list).next;
  phVar1 = (ptr->ordered_list).next;
  ((ptr->list).next)->prev = phVar4;
  phVar4 = (ptr->ordered_list).prev;
  phVar4->next = phVar1;
  ((ptr->ordered_list).next)->prev = phVar4;
  if ((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) {
    psVar5 = &json->refcount;
    DataMemoryBarrier(0x1f);
    do {
      ExclusiveAccess(psVar5);
      sVar2 = *psVar5;
      bVar8 = (bool)hasExclusiveAccess(psVar5);
    } while (!bVar8);
    *psVar5 = sVar2 - 1;
    if (sVar2 - 1 == 0) {
      json_delete(json);
    }
  }
  jsonp_free(ptr);
  hashtable->size = hashtable->size - 1;
  return 0;
}

