
/* WARNING: Unknown calling convention */

void _k_unlink_item(K_LIST *list,K_ITEM *item,char *file,char *func,int line)

{
  k_item *pkVar1;
  int iVar2;
  k_item *pkVar3;
  bool bVar4;
  char tmp42 [2048];
  
  if (item->name != list->name) {
    snprintf(tmp42,0x800,DAT_0001013c,list->name,DAT_00010138,item->name,file,func,line,DAT_00010140
             ,DAT_00010138,0x138);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar3 = item->prev;
  if (pkVar3 != (k_item *)0x0) {
    pkVar3->next = item->next;
  }
  pkVar1 = item->next;
  if (pkVar1 != (k_item *)0x0) {
    pkVar1->prev = pkVar3;
  }
  if (list->head == item) {
    list->head = pkVar1;
  }
  if (list->do_tail != false) {
    pkVar3 = list->tail;
    bVar4 = pkVar3 == item;
    if (bVar4) {
      pkVar3 = item->prev;
    }
    if (bVar4) {
      list->tail = pkVar3;
    }
  }
  iVar2 = list->count;
  item->next = (k_item *)0x0;
  item->prev = (k_item *)0x0;
  list->count = iVar2 + -1;
  return;
}

