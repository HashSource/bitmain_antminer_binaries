
/* WARNING: Unknown calling convention */

K_ITEM * _k_unlink_tail(K_LIST *list,char *file,char *func,int line)

{
  K_ITEM *pKVar1;
  K_ITEM *item;
  int iVar2;
  k_item *pkVar3;
  char tmp42 [2048];
  
  if (list->do_tail == false) {
    snprintf(tmp42,0x800,DAT_0000fd70,list->name,DAT_0000fd6c,file,func,line,DAT_0000fd74,
             DAT_0000fd6c,0xb5);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pKVar1 = list->tail;
  if (pKVar1 != (K_ITEM *)0x0) {
    pkVar3 = pKVar1->prev;
    list->tail = pkVar3;
    if (pkVar3 == (k_item *)0x0) {
      list->head = (k_item *)0x0;
    }
    else {
      pkVar3->next = (k_item *)0x0;
    }
    iVar2 = list->count;
    pKVar1->next = (k_item *)0x0;
    pKVar1->prev = (k_item *)0x0;
    list->count = iVar2 + -1;
  }
  return pKVar1;
}

