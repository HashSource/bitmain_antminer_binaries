
/* WARNING: Unknown calling convention */

K_ITEM * _k_unlink_head(K_LIST *list,char *file,char *func,int line)

{
  int iVar1;
  k_item *pkVar2;
  K_ITEM *item;
  
  item = list->head;
  if (item == (k_item *)0x0) {
    if (list->is_store != false) {
      return (K_ITEM *)0x0;
    }
    k_alloc_items(list,file,func,line);
    item = list->head;
    if (item == (k_item *)0x0) {
      return (K_ITEM *)0x0;
    }
  }
  pkVar2 = item->next;
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
  item->next = (k_item *)0x0;
  item->prev = (k_item *)0x0;
  list->count = iVar1 + -1;
  return item;
}

