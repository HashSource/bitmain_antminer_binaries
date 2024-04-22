
K_ITEM * _k_unlink_head(K_LIST *list,char *file,char *func,int line)

{
  k_item *pkVar1;
  int line_local;
  char *func_local;
  char *file_local;
  K_LIST *list_local;
  K_ITEM *item;
  
  if ((list->head == (k_item *)0x0) && (list->is_store != true)) {
    k_alloc_items(list,file,func,line);
  }
  if (list->head == (k_item *)0x0) {
    pkVar1 = (k_item *)0x0;
  }
  else {
    pkVar1 = list->head;
    list->head = pkVar1->next;
    if (list->head == (k_item *)0x0) {
      if (list->do_tail != false) {
        list->tail = (k_item *)0x0;
      }
    }
    else {
      list->head->prev = (k_item *)0x0;
    }
    pkVar1->next = (k_item *)0x0;
    pkVar1->prev = pkVar1->next;
    list->count = list->count + -1;
  }
  return pkVar1;
}

