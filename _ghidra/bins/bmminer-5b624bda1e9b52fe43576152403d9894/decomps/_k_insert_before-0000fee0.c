
/* WARNING: Unknown calling convention */

void _k_insert_before(K_LIST *list,K_ITEM *item,K_ITEM *before,char *file,char *func,int line)

{
  int iVar1;
  k_item *pkVar2;
  int iVar3;
  char tmp42 [2048];
  
  if (item->name != list->name) {
    snprintf(tmp42,0x800,"List %s can\'t %s() a %s item - from %s %s() line %d in %s %s():%d",
             list->name,"_k_insert_before",item->name,file,func,line,"klist.c","_k_insert_before",
             0x106);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (before == (K_ITEM *)0x0) {
    snprintf(tmp42,0x800,"%s() (%s) can\'t before a null item - from %s %s() line %d in %s %s():%d",
             "_k_insert_before",list->name,file,func,line,"klist.c","_k_insert_before",0x10b);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar2 = before->prev;
  item->next = before;
  item->prev = pkVar2;
  if (before->prev == (k_item *)0x0) {
    list->head = item;
  }
  else {
    before->prev->next = item;
  }
  iVar1 = list->count;
  iVar3 = list->count_up;
  before->prev = item;
  list->count = iVar1 + 1;
  list->count_up = iVar3 + 1;
  return;
}

