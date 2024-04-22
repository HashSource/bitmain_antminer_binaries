
/* WARNING: Unknown calling convention */

void _k_list_transfer_to_head(K_LIST *from,K_LIST *to,char *file,char *func,int line)

{
  k_item *pkVar1;
  int iVar2;
  k_item *pkVar3;
  k_item *pkVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char tmp42 [2048];
  
  if (from->name != to->name) {
    snprintf(tmp42,0x800,DAT_00010228,from->name,DAT_00010224,to->name,file,func,line,DAT_00010230,
             DAT_00010224,0x152);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (from->do_tail == false) {
    snprintf(tmp42,0x800,DAT_0001022c,from->name,DAT_00010224,file,func,line,DAT_00010230,
             DAT_00010224,0x157);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar3 = from->head;
  if (pkVar3 != (k_item *)0x0) {
    pkVar4 = to->head;
    if (pkVar4 == (k_item *)0x0) {
      to->tail = from->tail;
      pkVar1 = from->tail;
    }
    else {
      pkVar1 = from->tail;
      pkVar4->prev = pkVar1;
    }
    iVar6 = to->count;
    iVar7 = from->count;
    pkVar1->next = pkVar4;
    iVar2 = to->count_up;
    iVar5 = from->count_up;
    to->head = pkVar3;
    to->count = iVar6 + iVar7;
    from->tail = (k_item *)0x0;
    to->count_up = iVar2 + iVar5;
    from->head = (k_item *)0x0;
    from->count = 0;
    from->count_up = 0;
  }
  return;
}

