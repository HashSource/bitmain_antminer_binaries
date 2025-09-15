
void _k_unlink_item(K_LIST *list,K_ITEM *item,char *file,char *func,int line)

{
  char *func_local;
  char *file_local;
  K_ITEM *item_local;
  K_LIST *list_local;
  char tmp42 [2048];
  
  if (item->name != list->name) {
    snprintf(tmp42,0x800,"List %s can\'t %s() a %s item - from %s %s() line %d in %s %s():%d",
             list->name,"_k_unlink_item",item->name,file,func,line,"klist.c","_k_unlink_item",0x138)
    ;
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (item->prev != (k_item *)0x0) {
    item->prev->next = item->next;
  }
  if (item->next != (k_item *)0x0) {
    item->next->prev = item->prev;
  }
  if (list->head == item) {
    list->head = item->next;
  }
  if ((list->do_tail != false) && (list->tail == item)) {
    list->tail = item->prev;
  }
  item->next = (k_item *)0x0;
  item->prev = item->next;
  list->count = list->count + -1;
  return;
}

