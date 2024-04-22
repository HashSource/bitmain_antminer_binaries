
void k_alloc_items(K_LIST *list,char *file,char *func,int line)

{
  void **ppvVar1;
  k_item *pkVar2;
  void *pvVar3;
  int line_local;
  char *func_local;
  char *file_local;
  K_LIST *list_local;
  char tmp42 [2048];
  int i;
  int allocate;
  K_ITEM *item;
  
  if (list->is_store != false) {
    snprintf(tmp42,0x800,"List %s store can\'t %s() - from %s %s() line %d in %s %s():%d",list->name
             ,"k_alloc_items",file,func,line,"klist.c","k_alloc_items",0x14);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if ((list->limit < 1) || (list->total < list->limit)) {
    allocate = list->allocate;
    if ((0 < list->limit) && (list->limit < list->total + allocate)) {
      allocate = list->limit - list->total;
    }
    list->item_mem_count = list->item_mem_count + 1;
    ppvVar1 = (void **)realloc(list->item_memory,list->item_mem_count << 2);
    list->item_memory = ppvVar1;
    if (list->item_memory == (void **)0x0) {
      snprintf(tmp42,0x800,"List %s item_memory failed to realloc count=%d in %s %s():%d",list->name
               ,list->item_mem_count,"klist.c","k_alloc_items",0x23);
      _applog(3,tmp42,true);
      _quit(1);
    }
    pkVar2 = (k_item *)calloc(allocate,0x10);
    if (pkVar2 == (k_item *)0x0) {
      snprintf(tmp42,0x800,
               "List %s failed to calloc %d new items - total was %d, limit was %d in %s %s():%d",
               list->name,allocate,list->total,list->limit,"klist.c","k_alloc_items",0x29);
      _applog(3,tmp42,true);
      _quit(1);
    }
    list->item_memory[list->item_mem_count + 0x3fffffff] = pkVar2;
    list->total = list->total + allocate;
    list->count = allocate;
    list->count_up = allocate;
    pkVar2->name = list->name;
    pkVar2->prev = (k_item *)0x0;
    pkVar2->next = pkVar2 + 1;
    for (i = 1; i < allocate + -1; i = i + 1) {
      pkVar2[i].name = list->name;
      pkVar2[i].prev = pkVar2 + i + 0xfffffff;
      pkVar2[i].next = pkVar2 + i + 1;
    }
    pkVar2[allocate + 0xfffffff].name = list->name;
    pkVar2[allocate + 0xfffffff].prev = pkVar2 + allocate + 0xffffffe;
    pkVar2[allocate + 0xfffffff].next = (k_item *)0x0;
    list->head = pkVar2;
    if (list->do_tail != false) {
      list->tail = pkVar2 + allocate + 0xfffffff;
    }
    for (item = list->head; item != (K_ITEM *)0x0; item = item->next) {
      list->data_mem_count = list->data_mem_count + 1;
      ppvVar1 = (void **)realloc(list->data_memory,list->data_mem_count << 2);
      list->data_memory = ppvVar1;
      if (list->data_memory == (void **)0x0) {
        snprintf(tmp42,0x800,"List %s data_memory failed to realloc count=%d in %s %s():%d",
                 list->name,list->data_mem_count,"klist.c","k_alloc_items",0x4b);
        _applog(3,tmp42,true);
        _quit(1);
      }
      pvVar3 = calloc(1,list->siz);
      item->data = pvVar3;
      if (item->data == (void *)0x0) {
        snprintf(tmp42,0x800,"List %s failed to calloc item data in %s %s():%d",list->name,"klist.c"
                 ,"k_alloc_items",0x4f);
        _applog(3,tmp42,true);
        _quit(1);
      }
      list->data_memory[list->data_mem_count + 0x3fffffff] = item->data;
    }
  }
  return;
}

