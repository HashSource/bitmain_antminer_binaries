
/* WARNING: Unknown calling convention */

void hashtable_clear(hashtable_t *hashtable)

{
  hashtable_bucket *phVar1;
  int iVar2;
  int iVar3;
  
  hashtable_do_clear(hashtable);
  iVar3 = 1 << (hashtable->order & 0xff);
  if (iVar3 != 0) {
    phVar1 = hashtable->buckets;
    iVar2 = 0;
    do {
      *(hashtable_list **)((int)&phVar1->last + iVar2) = &hashtable->list;
      *(hashtable_list **)((int)&phVar1->first + iVar2) = &hashtable->list;
      iVar2 = iVar2 + 8;
    } while (iVar2 != iVar3 * 8);
  }
  (hashtable->list).next = &hashtable->list;
  (hashtable->list).prev = &hashtable->list;
  hashtable->size = 0;
  return;
}

