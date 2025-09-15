
void _k_add_head(K_LIST *list,K_ITEM *item,char *file,char *func,int line)

{
  char *func_local;
  char *file_local;
  K_ITEM *item_local;
  K_LIST *list_local;
  char tmp42 [2048];
  
  if (item->name != list->name) {
    snprintf(tmp42,0x800,"List %s can\'t %s() a %s item - from %s %s() line %d in %s %s():%d",
             list->name,"_k_add_head",item->name,file,func,line,"klist.c","_k_add_head",0xd6);
    _applog(3,tmp42,true);
    _quit(1);
  }
  item->prev = (k_item *)0x0;
  item->next = list->head;
  if (list->head != (k_item *)0x0) {
    list->head->prev = item;
  }
  list->head = item;
  if ((list->do_tail != false) && (list->tail == (k_item *)0x0)) {
    list->tail = item;
  }
  list->count = list->count + 1;
  list->count_up = list->count_up + 1;
  return;
}

