
/* WARNING: Unknown calling convention */

void hashtable_do_clear(hashtable_t *hashtable)

{
  bool bVar1;
  hashtable_list *ptr;
  hashtable_list *json;
  hashtable_list *phVar2;
  hashtable_list **pphVar3;
  hashtable_list *phVar4;
  
  ptr = (hashtable->list).next;
  while (ptr != &hashtable->list) {
    json = ptr[2].next;
    phVar4 = ptr->next;
    pphVar3 = &json->next;
    if ((json != (hashtable_list *)0x0) && (json->next != (hashtable_list *)0xffffffff)) {
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(pphVar3);
        phVar2 = (hashtable_list *)((int)&(*pphVar3)[-1].next + 3);
        bVar1 = (bool)hasExclusiveAccess(pphVar3);
      } while (!bVar1);
      *pphVar3 = phVar2;
      if (phVar2 == (hashtable_list *)0x0) {
        json_delete((json_t *)json);
      }
    }
    jsonp_free(ptr);
    ptr = phVar4;
  }
  return;
}

