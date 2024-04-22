
K_LIST * k_new_store(K_LIST *list)

{
  K_LIST *pKVar1;
  K_LIST *list_local;
  char tmp42 [2048];
  K_LIST *store;
  
  pKVar1 = (K_LIST *)calloc(1,0x40);
  if (pKVar1 == (K_LIST *)0x0) {
    snprintf(tmp42,0x800,"Failed to calloc store for %s in %s %s():%d",list->name,"klist.c",
             "k_new_store",0x55);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pKVar1->is_store = true;
  pKVar1->lock = list->lock;
  pKVar1->name = list->name;
  pKVar1->do_tail = list->do_tail;
  return pKVar1;
}

