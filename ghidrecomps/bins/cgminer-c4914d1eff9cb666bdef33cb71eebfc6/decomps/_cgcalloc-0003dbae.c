
void * _cgcalloc(int memb,size_t size,char *file,char *func,int line)

{
  void *pvVar1;
  char *func_local;
  char *file_local;
  size_t size_local;
  int memb_local;
  char tmp42 [2048];
  void *ret;
  
  size_local = size;
  memb_local = memb;
  align_len(&size_local);
  pvVar1 = calloc(memb_local,size_local);
  if (pvVar1 == (void *)0x0) {
    snprintf(tmp42,0x800,"Failed to calloc memb %d size %d from %s %s:%d",memb_local,size_local,file
             ,func,line);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return pvVar1;
}

