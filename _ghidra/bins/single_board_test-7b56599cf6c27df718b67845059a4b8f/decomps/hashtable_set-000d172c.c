
/* WARNING: Unknown calling convention */

int hashtable_set(hashtable_t *hashtable,char *key,json_t *value)

{
  bool bVar1;
  hashtable_bucket *phVar2;
  size_t length;
  hashtable_list *phVar3;
  pair_t *ppVar4;
  json_t *json;
  list_t *list;
  int extraout_r1;
  uint uVar5;
  size_t sVar6;
  size_t *psVar7;
  hashtable_list *phVar8;
  int iVar9;
  hashtable_list *phVar10;
  
  uVar5 = hashtable->order;
  if (hashtable->size >> (uVar5 & 0xff) != 0) {
    iVar9 = 1 << (uVar5 + 1 & 0xff);
    phVar2 = (hashtable_bucket *)jsonp_malloc(iVar9 * 8);
    if (phVar2 == (hashtable_bucket *)0x0) {
      return -1;
    }
    jsonp_free(hashtable->buckets);
    hashtable->order = uVar5 + 1;
    sVar6 = 0;
    hashtable->buckets = phVar2;
    if (iVar9 != 0) {
      do {
        *(hashtable_list **)((int)&phVar2->last + sVar6) = &hashtable->list;
        *(hashtable_list **)((int)&phVar2->first + sVar6) = &hashtable->list;
        sVar6 = sVar6 + 8;
      } while (sVar6 != iVar9 * 8);
    }
    phVar8 = (hashtable->list).next;
    phVar3 = &hashtable->list;
    phVar3->prev = phVar3;
    (hashtable->list).next = phVar3;
    if (phVar8 == phVar3) goto LAB_000d17b8;
    while( true ) {
      phVar10 = phVar8->next;
      __aeabi_uidivmod(phVar8[2].prev,iVar9);
      insert_to_bucket(hashtable,phVar2 + extraout_r1,phVar8);
      if (phVar3 == phVar10) break;
      phVar2 = hashtable->buckets;
      phVar8 = phVar10;
    }
    uVar5 = hashtable->order;
  }
  phVar2 = hashtable->buckets;
  iVar9 = 1 << (uVar5 & 0xff);
LAB_000d17b8:
  length = strlen(key);
  phVar3 = (hashtable_list *)hashlittle(key,length,hashtable_seed);
  ppVar4 = hashtable_find_pair(hashtable,phVar2 + (iVar9 - 1U & (uint)phVar3),key,(size_t)phVar3);
  if (ppVar4 != (pair_t *)0x0) {
    json = ppVar4->value;
    if ((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) {
      psVar7 = &json->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar7);
        sVar6 = *psVar7;
        bVar1 = (bool)hasExclusiveAccess(psVar7);
      } while (!bVar1);
      *psVar7 = sVar6 - 1;
      if (sVar6 - 1 == 0) {
        json_delete(json);
      }
    }
    ppVar4->value = value;
    return 0;
  }
  if ((length < 0xffffffe7) && (list = (list_t *)jsonp_malloc(length + 0x19), list != (list_t *)0x0)
     ) {
    list[2].prev = phVar3;
    strncpy((char *)(list + 3),key,length + 1);
    phVar8 = list + 1;
    list->next = list;
    list[2].next = (hashtable_list *)value;
    list->prev = list;
    list[1].next = phVar8;
    list[1].prev = phVar8;
    insert_to_bucket(hashtable,phVar2 + (iVar9 - 1U & (uint)phVar3),list);
    phVar3 = (hashtable->ordered_list).prev;
    sVar6 = hashtable->size;
    list[1].next = &hashtable->ordered_list;
    list[1].prev = phVar3;
    phVar3 = (hashtable->ordered_list).prev;
    (hashtable->ordered_list).prev = phVar8;
    phVar3->next = phVar8;
    hashtable->size = sVar6 + 1;
    return 0;
  }
  return -1;
}

