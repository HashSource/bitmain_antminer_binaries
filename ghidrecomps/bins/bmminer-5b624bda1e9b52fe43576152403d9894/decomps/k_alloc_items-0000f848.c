
/* WARNING: Unknown calling convention */

void k_alloc_items(K_LIST *list,char *file,char *func,int line)

{
  _Bool _Var1;
  undefined4 uVar2;
  undefined4 uVar3;
  void **ppvVar4;
  k_item *pkVar5;
  K_ITEM *item;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  k_item *pkVar10;
  char *pcVar11;
  uint uVar12;
  size_t __nmemb;
  int allocate;
  bool bVar13;
  char tmp42 [2048];
  
  if (list->is_store == false) {
    iVar9 = list->limit;
  }
  else {
    snprintf(tmp42,0x800,DAT_0000fa68,list->name,DAT_0000fa5c,file,func,line,DAT_0000fa58,
             DAT_0000fa5c,0x13);
    _applog(3,tmp42,true);
    _quit(1);
    iVar9 = list->limit;
  }
  if (iVar9 < 1) {
    __nmemb = list->allocate;
  }
  else {
    iVar7 = list->total;
    if (iVar9 <= iVar7) {
      return;
    }
    __nmemb = list->allocate;
    if (iVar9 < (int)(iVar7 + __nmemb)) {
      __nmemb = iVar9 - iVar7;
    }
  }
  iVar9 = list->item_mem_count + 1;
  list->item_mem_count = iVar9;
  ppvVar4 = (void **)realloc(list->item_memory,iVar9 * 4);
  list->item_memory = ppvVar4;
  if (ppvVar4 == (void **)0x0) {
    snprintf(tmp42,0x800,DAT_0000fa6c,list->name,list->item_mem_count,DAT_0000fa58,DAT_0000fa5c,0x21
            );
    _applog(3,tmp42,true);
    _quit(1);
  }
  pkVar5 = (k_item *)calloc(__nmemb,0x10);
  if (pkVar5 == (k_item *)0x0) {
    snprintf(tmp42,0x800,DAT_0000fa70,list->name,__nmemb,list->total,list->limit,DAT_0000fa58,
             DAT_0000fa5c,0x26);
    _applog(3,tmp42,true);
    _quit(1);
  }
  uVar12 = __nmemb - 1;
  bVar13 = (int)(__nmemb - 2) < 0;
  iVar9 = list->total;
  list->item_memory[list->item_mem_count + -1] = pkVar5;
  pcVar11 = list->name;
  pkVar10 = (k_item *)(iVar9 + __nmemb);
  list->total = (int)pkVar10;
  if (1 < (int)uVar12) {
    pkVar10 = pkVar5 + 2;
  }
  list->count = __nmemb;
  list->count_up = __nmemb;
  pkVar5->prev = (k_item *)0x0;
  uVar8 = (uint)(uVar12 != 1 && bVar13 == SBORROW4(uVar12,1));
  pkVar5->name = pcVar11;
  pkVar5->next = pkVar5 + 1;
  if (uVar12 != 1 && bVar13 == SBORROW4(uVar12,1)) {
    do {
      uVar8 = uVar8 + 1;
      pkVar10[-1].name = pcVar11;
      pkVar10[-1].next = pkVar10;
      pkVar10[-1].prev = pkVar10 + -2;
      pkVar10 = pkVar10 + 1;
    } while (uVar8 != uVar12);
  }
  _Var1 = list->do_tail;
  pkVar10 = pkVar5 + uVar12;
  pkVar5[uVar12].name = pcVar11;
  pkVar10->prev = pkVar5 + (__nmemb - 2);
  pkVar10->next = (k_item *)0x0;
  list->head = pkVar5;
  if (_Var1 != false) {
    list->tail = pkVar10;
  }
  uVar3 = DAT_0000fa5c;
  uVar2 = DAT_0000fa58;
  iVar9 = list->data_mem_count;
  do {
    list->data_mem_count = iVar9 + 1;
    ppvVar4 = (void **)realloc(list->data_memory,(iVar9 + 1) * 4);
    list->data_memory = ppvVar4;
    if (ppvVar4 == (void **)0x0) {
      snprintf(tmp42,0x800,DAT_0000fa60,list->name,list->data_mem_count,uVar2,uVar3,0x45);
      _applog(3,tmp42,true);
      _quit(1);
    }
    pvVar6 = calloc(1,list->siz);
    pkVar5->data = pvVar6;
    if (pvVar6 == (void *)0x0) {
      snprintf(tmp42,0x800,DAT_0000fa64,list->name,uVar2,uVar3,0x49);
      _applog(3,tmp42,true);
      _quit(1);
      pvVar6 = pkVar5->data;
    }
    iVar9 = list->data_mem_count;
    list->data_memory[iVar9 + -1] = pvVar6;
    pkVar5 = pkVar5->next;
  } while (pkVar5 != (k_item *)0x0);
  return;
}

