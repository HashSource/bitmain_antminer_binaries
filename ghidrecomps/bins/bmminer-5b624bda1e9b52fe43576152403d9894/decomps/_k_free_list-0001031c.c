
/* WARNING: Unknown calling convention */

K_LIST * _k_free_list(K_LIST *list,char *file,char *func,int line)

{
  void **ppvVar1;
  int iVar2;
  pthread_mutex_t *__mutex;
  char tmp42 [2048];
  
  if (list->is_store != false) {
    snprintf(tmp42,0x800,"List %s can\'t %s() a store - from %s %s() line %d in %s %s():%d",
             list->name,"_k_free_list",file,func,line,"klist.c","_k_free_list",400);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (0 < list->item_mem_count) {
    iVar2 = 0;
    do {
      ppvVar1 = list->item_memory + iVar2;
      iVar2 = iVar2 + 1;
      free(*ppvVar1);
    } while (iVar2 < list->item_mem_count);
  }
  free(list->item_memory);
  if (0 < list->data_mem_count) {
    iVar2 = 0;
    do {
      ppvVar1 = list->data_memory + iVar2;
      iVar2 = iVar2 + 1;
      free(*ppvVar1);
    } while (iVar2 < list->data_mem_count);
  }
  free(list->data_memory);
  __mutex = (pthread_mutex_t *)list->lock;
  pthread_rwlock_destroy((pthread_rwlock_t *)(__mutex + 1));
  pthread_mutex_destroy(__mutex);
  free(list->lock);
  free(list);
  return (K_LIST *)0x0;
}

