
/* WARNING: Unknown calling convention */

pair_t * hashtable_find_pair(hashtable_t *hashtable,bucket_t *bucket,char *key,size_t hash)

{
  int iVar1;
  pair_t *ppVar2;
  
  ppVar2 = (pair_t *)bucket->first;
  if ((ppVar2 != (pair_t *)&hashtable->list) || (ppVar2 != (pair_t *)bucket->last)) {
    while( true ) {
      if ((ppVar2->hash == hash) && (iVar1 = strcmp(ppVar2->key,key), iVar1 == 0)) {
        return ppVar2;
      }
      if ((pair_t *)bucket->last == ppVar2) break;
      ppVar2 = (pair_t *)(ppVar2->list).next;
    }
  }
  return (pair_t *)0x0;
}

