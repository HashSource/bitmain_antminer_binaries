
/* WARNING: Unknown calling convention */

void _k_add_head(K_LIST *list,K_ITEM *item,char *file,char *func,int line)

{
  k_item *pkVar1;
  char tmp42 [2048];
  
  if (item->name != list->name) {
    snprintf(tmp42,0x800,DAT_0000fe00,list->name,DAT_0000fdfc,item->name,file,func,line,DAT_0000fe04
             ,DAT_0000fdfc,0xcd);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar1 = list->head;
  item->prev = (k_item *)0x0;
  item->next = pkVar1;
  if (pkVar1 != (k_item *)0x0) {
    pkVar1->prev = item;
  }
  list->head = item;
  if ((list->do_tail != false) && (list->tail == (k_item *)0x0)) {
    list->tail = item;
  }
  list->count = list->count + 1;
  list->count_up = list->count_up + 1;
  return;
}

