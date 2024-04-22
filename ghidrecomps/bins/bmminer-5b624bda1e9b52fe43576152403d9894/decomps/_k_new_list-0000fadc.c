
/* WARNING: Unknown calling convention */

K_LIST * _k_new_list(char *name,size_t siz,int allocate,int limit,_Bool do_tail,char *file,
                    char *func,int line)

{
  K_LIST *list_00;
  K_LIST *list;
  cglock_t *__mutex;
  int iVar1;
  int *piVar2;
  char tmp42 [2048];
  
  if (allocate < 1) {
    snprintf(tmp42,0x800,DAT_0000fc84,name,allocate,DAT_0000fc7c,DAT_0000fc80,100);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (limit < 0) {
    snprintf(tmp42,0x800,DAT_0000fc88,name,limit,DAT_0000fc7c,DAT_0000fc80,0x67);
    _applog(3,tmp42,true);
    _quit(1);
  }
  list_00 = (K_LIST *)calloc(1,0x40);
  if (list_00 == (K_LIST *)0x0) {
    snprintf(tmp42,0x800,DAT_0000fc90,name,DAT_0000fc7c,DAT_0000fc80,0x6b);
    _applog(3,tmp42,true);
    _quit(1);
  }
  list_00->is_store = false;
  __mutex = (cglock_t *)calloc(1,0x38);
  list_00->lock = __mutex;
  if (__mutex == (cglock_t *)0x0) {
    snprintf(tmp42,0x800,DAT_0000fc8c,name,DAT_0000fc7c,DAT_0000fc80,0x71);
    _applog(3,tmp42,true);
    _quit(1);
    __mutex = list_00->lock;
  }
  iVar1 = pthread_mutex_init((pthread_mutex_t *)__mutex,(pthread_mutexattr_t *)0x0);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,DAT_0000fc98,*piVar2,DAT_0000fc7c,DAT_0000fc80,0x73);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_rwlock_init((pthread_rwlock_t *)&__mutex->rwlock,(pthread_rwlockattr_t *)0x0);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,DAT_0000fc94,*piVar2,DAT_0000fc7c,DAT_0000fc80,0x73);
    _applog(3,tmp42,true);
    _quit(1);
  }
  list_00->name = name;
  list_00->siz = siz;
  list_00->allocate = allocate;
  list_00->limit = limit;
  list_00->do_tail = do_tail;
  k_alloc_items(list_00,file,func,line);
  return list_00;
}

