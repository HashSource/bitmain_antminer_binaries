
/* WARNING: Unknown calling convention */

void k_alloc_items(K_LIST *list,char *file,char *func,int line)

{
  _Bool _Var1;
  void **ppvVar2;
  k_item *pkVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  k_item *pkVar8;
  char *pcVar9;
  uint uVar10;
  size_t __nmemb;
  bool bVar11;
  char tmp42 [2048];
  
  if (list->is_store == false) {
    iVar7 = list->limit;
  }
  else {
    snprintf(tmp42,0x800,"List %s store can\'t %s() - from %s %s() line %d in %s %s():%d",list->name
             ,"k_alloc_items",file,func,line,"klist.c","k_alloc_items",0x13);
    _applog(3,tmp42,true);
    _quit(1);
    iVar7 = list->limit;
  }
  if (iVar7 < 1) {
    __nmemb = list->allocate;
  }
  else {
    iVar5 = list->total;
    if (iVar7 <= iVar5) {
      return;
    }
    __nmemb = list->allocate;
    if (iVar7 < (int)(iVar5 + __nmemb)) {
      __nmemb = iVar7 - iVar5;
    }
  }
  iVar7 = list->item_mem_count + 1;
  list->item_mem_count = iVar7;
  ppvVar2 = (void **)realloc(list->item_memory,iVar7 * 4);
  list->item_memory = ppvVar2;
  if (ppvVar2 == (void **)0x0) {
    snprintf(tmp42,0x800,"List %s item_memory failed to realloc count=%d in %s %s():%d",list->name,
             list->item_mem_count,"klist.c","k_alloc_items",0x21);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar3 = (k_item *)calloc(__nmemb,0x10);
  if (pkVar3 == (k_item *)0x0) {
    snprintf(tmp42,0x800,
             "List %s failed to calloc %d new items - total was %d, limit was %d in %s %s():%d",
             list->name,__nmemb,list->total,list->limit,"klist.c","k_alloc_items",0x26);
    _applog(3,tmp42,true);
    _quit(1);
  }
  uVar10 = __nmemb - 1;
  bVar11 = (int)(__nmemb - 2) < 0;
  iVar7 = list->total;
  list->item_memory[list->item_mem_count + -1] = pkVar3;
  pcVar9 = list->name;
  pkVar8 = (k_item *)(iVar7 + __nmemb);
  list->total = (int)pkVar8;
  if (1 < (int)uVar10) {
    pkVar8 = pkVar3 + 2;
  }
  list->count = __nmemb;
  list->count_up = __nmemb;
  pkVar3->prev = (k_item *)0x0;
  uVar6 = (uint)(uVar10 != 1 && bVar11 == SBORROW4(uVar10,1));
  pkVar3->name = pcVar9;
  pkVar3->next = pkVar3 + 1;
  if (uVar10 != 1 && bVar11 == SBORROW4(uVar10,1)) {
    do {
      uVar6 = uVar6 + 1;
      pkVar8[-1].name = pcVar9;
      pkVar8[-1].next = pkVar8;
      pkVar8[-1].prev = pkVar8 + -2;
      pkVar8 = pkVar8 + 1;
    } while (uVar6 != uVar10);
  }
  _Var1 = list->do_tail;
  pkVar8 = pkVar3 + uVar10;
  pkVar3[uVar10].name = pcVar9;
  pkVar8->prev = pkVar3 + (__nmemb - 2);
  pkVar8->next = (k_item *)0x0;
  list->head = pkVar3;
  if (_Var1 != false) {
    list->tail = pkVar8;
  }
  iVar7 = list->data_mem_count;
  do {
    list->data_mem_count = iVar7 + 1;
    ppvVar2 = (void **)realloc(list->data_memory,(iVar7 + 1) * 4);
    list->data_memory = ppvVar2;
    if (ppvVar2 == (void **)0x0) {
      snprintf(tmp42,0x800,"List %s data_memory failed to realloc count=%d in %s %s():%d",list->name
               ,list->data_mem_count,"klist.c","k_alloc_items",0x45);
      _applog(3,tmp42,true);
      _quit(1);
    }
    pvVar4 = calloc(1,list->siz);
    pkVar3->data = pvVar4;
    if (pvVar4 == (void *)0x0) {
      snprintf(tmp42,0x800,"List %s failed to calloc item data in %s %s():%d",list->name,"klist.c",
               "k_alloc_items",0x49);
      _applog(3,tmp42,true);
      _quit(1);
      pvVar4 = pkVar3->data;
    }
    iVar7 = list->data_mem_count;
    list->data_memory[iVar7 + -1] = pvVar4;
    pkVar3 = pkVar3->next;
  } while (pkVar3 != (k_item *)0x0);
  return;
}

