
/* WARNING: Unknown calling convention */

void _k_list_transfer_to_tail(K_LIST *from,K_LIST *to,char *file,char *func,int line)

{
  int iVar1;
  k_item *pkVar2;
  k_item *pkVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char tmp42 [2048];
  
  if (from->name != to->name) {
    snprintf(tmp42,0x800,DAT_00010310,from->name,DAT_0001030c,to->name,file,func,line,DAT_00010318,
             DAT_0001030c,0x170);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (from->do_tail == false) {
    snprintf(tmp42,0x800,DAT_00010314,from->name,DAT_0001030c,file,func,line,DAT_00010318,
             DAT_0001030c,0x175);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar3 = from->head;
  if (pkVar3 != (k_item *)0x0) {
    pkVar2 = to->tail;
    if (pkVar2 == (k_item *)0x0) {
      to->head = pkVar3;
      pkVar3 = from->head;
    }
    else {
      pkVar2->next = pkVar3;
    }
    iVar6 = to->count;
    iVar5 = from->count;
    iVar1 = to->count_up;
    pkVar3->prev = pkVar2;
    iVar4 = from->count_up;
    pkVar3 = from->tail;
    to->count = iVar6 + iVar5;
    from->head = (k_item *)0x0;
    to->count_up = iVar1 + iVar4;
    to->tail = pkVar3;
    from->count = 0;
    from->tail = (k_item *)0x0;
    from->count_up = 0;
  }
  return;
}

