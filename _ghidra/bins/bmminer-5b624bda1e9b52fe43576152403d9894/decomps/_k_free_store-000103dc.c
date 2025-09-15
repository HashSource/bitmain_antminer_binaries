
/* WARNING: Unknown calling convention */

K_LIST * _k_free_store(K_LIST *store,char *file,char *func,int line)

{
  char tmp42 [2048];
  
  if (store->is_store == false) {
    snprintf(tmp42,0x800,"Store %s can\'t %s() the list - from %s %s() line %d in %s %s():%d",
             store->name,"_k_free_store",file,func,line,"klist.c","_k_free_store",0x1a8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  free(store);
  return (K_LIST *)0x0;
}

