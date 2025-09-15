
/* WARNING: Unknown calling convention */

void _k_insert_after(K_LIST *list,K_ITEM *item,K_ITEM *after,char *file,char *func,int line)

{
  int iVar1;
  k_item *pkVar2;
  int iVar3;
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
  pkVar2 = after->next;
  item->prev = after;
  item->next = pkVar2;
  if (after->next == (k_item *)0x0) {
    if (list->do_tail != false) {
      list->tail = item;
    }
  }
  else {
    after->next->prev = item;
  }
  iVar1 = list->count;
  iVar3 = list->count_up;
  after->next = item;
  list->count = iVar1 + 1;
  list->count_up = iVar3 + 1;
  return;
}

