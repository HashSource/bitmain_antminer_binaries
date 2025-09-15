
K_LIST * _k_new_list(char *name,size_t siz,int allocate,int limit,_Bool do_tail,char *file,
                    char *func,int line)

{
  K_LIST *list_00;
  cglock_t *pcVar1;
  int limit_local;
  int allocate_local;
  size_t siz_local;
  char *name_local;
  char tmp42 [2048];
  K_LIST *list;
  
  if (allocate < 1) {
    snprintf(tmp42,0x800,"Invalid new list %s with allocate %d must be > 0 in %s %s():%d",name,
             allocate,"klist.c","_k_new_list",100);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (limit < 0) {
    snprintf(tmp42,0x800,"Invalid new list %s with limit %d must be >= 0 in %s %s():%d",name,limit,
             "klist.c","_k_new_list",0x67);
    _applog(3,tmp42,true);
    _quit(1);
  }
  list_00 = (K_LIST *)calloc(1,0x40);
  if (list_00 == (K_LIST *)0x0) {
    snprintf(tmp42,0x800,"Failed to calloc list %s in %s %s():%d",name,"klist.c","_k_new_list",0x6b)
    ;
    _applog(3,tmp42,true);
    _quit(1);
  }
  list_00->is_store = false;
  pcVar1 = (cglock_t *)calloc(1,0x38);
  list_00->lock = pcVar1;
  if (list_00->lock == (cglock_t *)0x0) {
    snprintf(tmp42,0x800,"Failed to calloc lock for list %s in %s %s():%d",name,"klist.c",
             "_k_new_list",0x71);
    _applog(3,tmp42,true);
    _quit(1);
  }
  _cglock_init(list_00->lock,"klist.c","_k_new_list",0x73);
  list_00->name = name;
  list_00->siz = siz;
  list_00->allocate = allocate;
  list_00->limit = limit;
  list_00->do_tail = do_tail;
  k_alloc_items(list_00,file,func,line);
  return list_00;
}

