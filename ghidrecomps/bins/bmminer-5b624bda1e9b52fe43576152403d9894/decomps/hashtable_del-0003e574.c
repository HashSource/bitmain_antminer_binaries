
/* WARNING: Unknown calling convention */

int hashtable_del(hashtable_t *hashtable,char *key)

{
  size_t length;
  uint32_t hash_00;
  size_t hash;
  pair_t *pair;
  json_t *json;
  int iVar1;
  hashtable_list *phVar2;
  hashtable_list *phVar3;
  size_t sVar4;
  hashtable_list *phVar5;
  uint uVar6;
  hashtable_bucket *phVar7;
  bucket_t *bucket;
  bucket_t *bucket_00;
  bool bVar8;
  pair_t *local_1c [2];
  
  length = strlen(key);
  hash_00 = hashlittle(key,length,*DAT_0003e618);
  phVar7 = hashtable->buckets;
  uVar6 = (1 << (hashtable->order & 0xff)) - 1U & hash_00;
  bucket_00 = phVar7 + uVar6;
  local_1c[0] = hashtable_find_pair(hashtable,bucket_00,key,hash_00);
  if (local_1c[0] == (pair_t *)0x0) {
    iVar1 = -1;
  }
  else {
    phVar3 = &local_1c[0]->list;
    phVar2 = bucket_00->last;
    if (phVar3 == phVar7[uVar6].first) {
      if (phVar3 != phVar2) {
        phVar5 = (local_1c[0]->list).next;
      }
      else {
        phVar5 = &hashtable->list;
      }
      if (phVar3 == phVar2) {
        bucket_00->last = phVar5;
      }
      phVar7[uVar6].first = phVar5;
    }
    else {
      bVar8 = phVar3 == phVar2;
      if (bVar8) {
        phVar3 = (local_1c[0]->list).prev;
      }
      if (bVar8) {
        bucket_00->last = phVar3;
      }
    }
    phVar2 = (local_1c[0]->list).prev;
    json = local_1c[0]->value;
    phVar2->next = (local_1c[0]->list).next;
    ((local_1c[0]->list).next)->prev = phVar2;
    if (((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) &&
       (sVar4 = json->refcount - 1, json->refcount = sVar4, sVar4 == 0)) {
      json_delete(json);
    }
    _jsonp_free(local_1c);
    iVar1 = 0;
    hashtable->size = hashtable->size - 1;
  }
  return iVar1;
}

