
/* WARNING: Unknown calling convention */

pair_t * hashtable_find_pair(hashtable_t *hashtable,bucket_t *bucket,char *key,size_t hash)

{
  int iVar1;
  hashtable_list *phVar2;
  list_t *list;
  
  phVar2 = bucket->first;
  if ((phVar2 != &hashtable->list) || (phVar2 != bucket->last)) {
    while( true ) {
      if (phVar2[-1].next == (hashtable_list *)hash) {
        iVar1 = strcmp((char *)(phVar2 + 2),key);
        if (iVar1 == 0) {
          return (pair_t *)&phVar2[-1].next;
        }
      }
      if (bucket->last == phVar2) break;
      phVar2 = phVar2->next;
    }
  }
  return (pair_t *)0x0;
}

