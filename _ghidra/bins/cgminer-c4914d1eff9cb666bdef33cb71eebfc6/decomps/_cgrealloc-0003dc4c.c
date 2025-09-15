
void * _cgrealloc(void *ptr,size_t size,char *file,char *func,int line)

{
  void *pvVar1;
  char *func_local;
  char *file_local;
  size_t size_local;
  void *ptr_local;
  char tmp42 [2048];
  void *ret;
  
  size_local = size;
  ptr_local = ptr;
  align_len(&size_local);
  pvVar1 = realloc(ptr_local,size_local);
  if (pvVar1 == (void *)0x0) {
    snprintf(tmp42,0x800,"Failed to realloc size %d from %s %s:%d",size_local,file,func,line);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return pvVar1;
}

