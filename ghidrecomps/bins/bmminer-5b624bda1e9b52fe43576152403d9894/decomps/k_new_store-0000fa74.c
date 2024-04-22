
/* WARNING: Unknown calling convention */

K_LIST * k_new_store(K_LIST *list)

{
  _Bool _Var1;
  K_LIST *pKVar2;
  K_LIST *store;
  char *pcVar3;
  char tmp42 [2048];
  
  pKVar2 = (K_LIST *)calloc(1,0x40);
  if (pKVar2 == (K_LIST *)0x0) {
    snprintf(tmp42,0x800,DAT_0000fad8,list->name,DAT_0000fad0,DAT_0000fad4,0x55);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pcVar3 = list->name;
  _Var1 = list->do_tail;
  pKVar2->lock = list->lock;
  pKVar2->name = pcVar3;
  pKVar2->do_tail = _Var1;
  pKVar2->is_store = true;
  return pKVar2;
}

