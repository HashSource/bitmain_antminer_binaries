
/* WARNING: Unknown calling convention */

void _k_add_tail(K_LIST *list,K_ITEM *item,char *file,char *func,int line)

{
  k_item *pkVar1;
  char tmp42 [2048];
  
  if (item->name != list->name) {
    snprintf(tmp42,0x800,DAT_0000fed4,list->name,DAT_0000fed0,item->name,file,func,line,DAT_0000fedc
             ,DAT_0000fed0,0xec);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (list->do_tail == false) {
    snprintf(tmp42,0x800,DAT_0000fed8,list->name,DAT_0000fed0,file,func,line,DAT_0000fedc,
             DAT_0000fed0,0xf1);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar1 = list->tail;
  item->next = (k_item *)0x0;
  item->prev = pkVar1;
  if (pkVar1 != (k_item *)0x0) {
    pkVar1->next = item;
  }
  list->tail = item;
  if (list->head == (k_item *)0x0) {
    list->head = item;
  }
  list->count = list->count + 1;
  list->count_up = list->count_up + 1;
  return;
}

