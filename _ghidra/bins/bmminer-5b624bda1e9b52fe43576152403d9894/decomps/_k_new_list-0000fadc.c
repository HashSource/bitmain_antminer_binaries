
/* WARNING: Unknown calling convention */

K_LIST * _k_new_list(char *name,size_t siz,int allocate,int limit,_Bool do_tail,char *file,
                    char *func,int line)

{
  K_LIST *list;
  pthread_mutex_t *__mutex;
  int iVar1;
  int *piVar2;
  char tmp42 [2048];
  
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
  list = (K_LIST *)calloc(1,0x40);
  if (list == (K_LIST *)0x0) {
    snprintf(tmp42,0x800,"Failed to calloc list %s in %s %s():%d",name,"klist.c","_k_new_list",0x6b)
    ;
    _applog(3,tmp42,true);
    _quit(1);
  }
  list->is_store = false;
  __mutex = (pthread_mutex_t *)calloc(1,0x38);
  list->lock = (cglock_t *)__mutex;
  if (__mutex == (pthread_mutex_t *)0x0) {
    snprintf(tmp42,0x800,"Failed to calloc lock for list %s in %s %s():%d",name,"klist.c",
             "_k_new_list",0x71);
    _applog(3,tmp42,true);
    _quit(1);
    __mutex = (pthread_mutex_t *)list->lock;
  }
  iVar1 = pthread_mutex_init(__mutex,(pthread_mutexattr_t *)0x0);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar2,"klist.c",
             "_k_new_list",0x73);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_rwlock_init((pthread_rwlock_t *)(__mutex + 1),(pthread_rwlockattr_t *)0x0);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",*piVar2,"klist.c",
             "_k_new_list",0x73);
    _applog(3,tmp42,true);
    _quit(1);
  }
  list->name = name;
  list->siz = siz;
  list->allocate = allocate;
  list->limit = limit;
  list->do_tail = do_tail;
  k_alloc_items(list,file,func,line);
  return list;
}

