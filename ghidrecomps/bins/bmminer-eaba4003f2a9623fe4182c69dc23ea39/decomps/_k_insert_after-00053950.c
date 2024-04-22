
void _k_insert_after(K_LIST *list,K_ITEM *item,K_ITEM *after,char *file,char *func,int line)

{
  char *file_local;
  K_ITEM *after_local;
  K_ITEM *item_local;
  K_LIST *list_local;
  char tmp42 [2048];
  
  if (item->name != list->name) {
    snprintf(tmp42,0x800,"List %s can\'t %s() a %s item - from %s %s() line %d in %s %s():%d",
             list->name,"_k_insert_after",item->name,file,func,line,"klist.c","_k_insert_after",
             0x11e);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (after == (K_ITEM *)0x0) {
    snprintf(tmp42,0x800,"%s() (%s) can\'t after a null item - from %s %s() line %d in %s %s():%d",
             "_k_insert_after",list->name,file,func,line,"klist.c","_k_insert_after",0x123);
    _applog(3,tmp42,true);
    _quit(1);
  }
  item->prev = after;
  item->next = after->next;
  if (after->next == (k_item *)0x0) {
    if (list->do_tail != false) {
      list->tail = item;
    }
  }
  else {
    after->next->prev = item;
  }
  after->next = item;
  list->count = list->count + 1;
  list->count_up = list->count_up + 1;
  return;
}

