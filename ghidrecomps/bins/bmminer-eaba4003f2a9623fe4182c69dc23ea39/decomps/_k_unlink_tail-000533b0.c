
K_ITEM * _k_unlink_tail(K_LIST *list,char *file,char *func,int line)

{
  k_item *pkVar1;
  int line_local;
  char *func_local;
  char *file_local;
  K_LIST *list_local;
  char tmp42 [2048];
  K_ITEM *item;
  
  if (list->do_tail != true) {
    snprintf(tmp42,0x800,
             "List %s can\'t %s() - do_tail is false - from %s %s() line %d in %s %s():%d",
             list->name,"_k_unlink_tail",file,func,line,"klist.c","_k_unlink_tail",0xb5);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (list->tail == (k_item *)0x0) {
    pkVar1 = (k_item *)0x0;
  }
  else {
    pkVar1 = list->tail;
    list->tail = pkVar1->prev;
    if (list->tail == (k_item *)0x0) {
      list->head = (k_item *)0x0;
    }
    else {
      list->tail->next = (k_item *)0x0;
    }
    pkVar1->next = (k_item *)0x0;
    pkVar1->prev = pkVar1->next;
    list->count = list->count + -1;
  }
  return pkVar1;
}

