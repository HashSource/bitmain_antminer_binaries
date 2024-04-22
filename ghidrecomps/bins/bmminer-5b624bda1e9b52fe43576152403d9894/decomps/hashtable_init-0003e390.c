
/* WARNING: Unknown calling convention */

int hashtable_init(hashtable_t *hashtable)

{
  hashtable_bucket *phVar1;
  uint uVar2;
  hashtable_list *phVar3;
  int iVar4;
  int iVar5;
  
  hashtable->order = 3;
  hashtable->size = 0;
  phVar1 = (hashtable_bucket *)jsonp_malloc(0x40);
  hashtable->buckets = phVar1;
  if (phVar1 == (hashtable_bucket *)0x0) {
    return -1;
  }
  uVar2 = hashtable->order;
  phVar3 = &hashtable->list;
  (hashtable->list).next = phVar3;
  (hashtable->list).prev = phVar3;
  iVar5 = 1 << (uVar2 & 0xff);
  if (iVar5 != 0) {
    iVar4 = 0;
    do {
      *(hashtable_list **)((int)&phVar1->last + iVar4) = phVar3;
      *(hashtable_list **)((int)&phVar1->first + iVar4) = phVar3;
      iVar4 = iVar4 + 8;
    } while (iVar4 != iVar5 << 3);
  }
  return 0;
}

