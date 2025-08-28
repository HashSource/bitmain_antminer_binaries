
/* WARNING: Unknown calling convention */

K_ITEM * _k_unlink_head(K_LIST *list,char *file,char *func,int line)

{
  int iVar1;
  k_item *pkVar2;
  k_item *pkVar3;
  
  pkVar3 = list->head;
  if (pkVar3 == (k_item *)0x0) {
    if (list->is_store != false) {
      return (K_ITEM *)0x0;
    }
    k_alloc_items(list,file,func,line);
    pkVar3 = list->head;
    if (pkVar3 == (k_item *)0x0) {
      return (K_ITEM *)0x0;
    }
  }
  pkVar2 = pkVar3->next;
  list->head = pkVar2;
  if (pkVar2 == (k_item *)0x0) {
    if (list->do_tail != false) {
      list->tail = (k_item *)0x0;
    }
  }
  else {
    pkVar2->prev = (k_item *)0x0;
  }
  iVar1 = list->count;
  pkVar3->next = (k_item *)0x0;
  pkVar3->prev = (k_item *)0x0;
  list->count = iVar1 + -1;
  return pkVar3;
}

