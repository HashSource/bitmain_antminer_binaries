
K_LIST * _k_free_list(K_LIST *list,char *file,char *func,int line)

{
  int line_local;
  char *func_local;
  char *file_local;
  K_LIST *list_local;
  char tmp42 [2048];
  int i;
  
  if (list->is_store != false) {
    snprintf(tmp42,0x800,"List %s can\'t %s() a store - from %s %s() line %d in %s %s():%d",
             list->name,"_k_free_list",file,func,line,"klist.c","_k_free_list",400);
    _applog(3,tmp42,true);
    _quit(1);
  }
  for (i = 0; i < list->item_mem_count; i = i + 1) {
    free(list->item_memory[i]);
  }
  free(list->item_memory);
  for (i = 0; i < list->data_mem_count; i = i + 1) {
    free(list->data_memory[i]);
  }
  free(list->data_memory);
  cglock_destroy(list->lock);
  free(list->lock);
  free(list);
  return (K_LIST *)0x0;
}

