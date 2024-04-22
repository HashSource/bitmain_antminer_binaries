
/* WARNING: Unknown calling convention */

K_LIST * _k_free_store(K_LIST *store,char *file,char *func,int line)

{
  char tmp42 [2048];
  
  if (store->is_store == false) {
    snprintf(tmp42,0x800,DAT_00010438,store->name,DAT_00010434,file,func,line,DAT_0001043c,
             DAT_00010434,0x1a8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  free(store);
  return (K_LIST *)0x0;
}

