
/* WARNING: Unknown calling convention */

int hashtable_set(hashtable_t *hashtable,char *key,size_t serial,json_t *value)

{
  hashtable_list *phVar1;
  size_t length;
  uint32_t hash_00;
  size_t hash;
  pair_t *ppVar2;
  pair_t *pair;
  json_t *json;
  uint32_t *puVar3;
  int extraout_r1;
  list_t *list_00;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  hashtable_list *list_01;
  list_t *list;
  list_t *next;
  hashtable_bucket *phVar7;
  bucket_t *bucket;
  int iVar8;
  size_t new_size;
  int iVar9;
  hashtable_list *phVar10;
  
  if (hashtable->size >> (hashtable->order & 0xff) == 0) {
    phVar7 = hashtable->buckets;
    iVar9 = 1 << (hashtable->order & 0xff);
  }
  else {
    _jsonp_free(&hashtable->buckets);
    uVar5 = hashtable->order + 1;
    iVar8 = 1 << (uVar5 & 0xff);
    hashtable->order = uVar5;
    phVar7 = (hashtable_bucket *)jsonp_malloc(iVar8 << 3);
    hashtable->buckets = phVar7;
    if (phVar7 == (hashtable_bucket *)0x0) {
      return -1;
    }
    iVar9 = 1 << (hashtable->order & 0xff);
    if (iVar9 != 0) {
      iVar6 = 0;
      do {
        *(hashtable_list **)((int)&phVar7->last + iVar6) = &hashtable->list;
        *(hashtable_list **)((int)&phVar7->first + iVar6) = &hashtable->list;
        iVar6 = iVar6 + 8;
      } while (iVar6 != iVar9 << 3);
    }
    list_01 = (hashtable->list).next;
    phVar1 = &hashtable->list;
    phVar1->prev = phVar1;
    (hashtable->list).next = phVar1;
    if (list_01 != phVar1) {
      while( true ) {
        phVar10 = list_01->next;
        __aeabi_uidivmod(list_01[-1].next,iVar8);
        insert_to_bucket(hashtable,phVar7 + extraout_r1,list_01);
        if (phVar1 == phVar10) break;
        phVar7 = hashtable->buckets;
        list_01 = phVar10;
      }
      phVar7 = hashtable->buckets;
      iVar9 = 1 << (hashtable->order & 0xff);
    }
  }
  length = strlen(key);
  hash_00 = hashlittle(key,length,*DAT_0003e530);
  ppVar2 = hashtable_find_pair(hashtable,phVar7 + (iVar9 - 1U & hash_00),key,hash_00);
  if (ppVar2 == (pair_t *)0x0) {
    puVar3 = (uint32_t *)jsonp_malloc(length + 0x15);
    if (puVar3 == (uint32_t *)0x0) {
      return -1;
    }
    *puVar3 = hash_00;
    puVar3[4] = serial;
    strcpy((char *)(puVar3 + 5),key);
    list_00 = (list_t *)(puVar3 + 1);
    puVar3[3] = (uint32_t)value;
    puVar3[2] = (uint32_t)list_00;
    puVar3[1] = (uint32_t)list_00;
    insert_to_bucket(hashtable,phVar7 + (iVar9 - 1U & hash_00),list_00);
    hashtable->size = hashtable->size + 1;
    return 0;
  }
  json = ppVar2->value;
  if (((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) &&
     (sVar4 = json->refcount - 1, json->refcount = sVar4, sVar4 == 0)) {
    json_delete(json);
  }
  ppVar2->value = value;
  return 0;
}

