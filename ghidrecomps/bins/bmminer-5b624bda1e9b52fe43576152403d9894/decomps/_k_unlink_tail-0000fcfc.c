
/* WARNING: Unknown calling convention */

K_ITEM * _k_unlink_tail(K_LIST *list,char *file,char *func,int line)

{
  k_item *pkVar1;
  int iVar2;
  k_item *pkVar3;
  char tmp42 [2048];
  
  if (list->do_tail == false) {
    snprintf(tmp42,0x800,
             "List %s can\'t %s() - do_tail is false - from %s %s() line %d in %s %s():%d",
             list->name,"_k_unlink_tail",file,func,line,"klist.c","_k_unlink_tail",0xb5);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar1 = list->tail;
  if (pkVar1 != (k_item *)0x0) {
    pkVar3 = pkVar1->prev;
    list->tail = pkVar3;
    if (pkVar3 == (k_item *)0x0) {
      list->head = (k_item *)0x0;
    }
    else {
      pkVar3->next = (k_item *)0x0;
    }
    iVar2 = list->count;
    pkVar1->next = (k_item *)0x0;
    pkVar1->prev = (k_item *)0x0;
    list->count = iVar2 + -1;
  }
  return pkVar1;
}

