
void * _cgmalloc(uint size,char *file,char *func,int line)

{
  void *pvVar1;
  int line_local;
  char *func_local;
  char *file_local;
  uint size_local;
  char tmp42 [2048];
  void *ret;
  
  size_local = size;
  align_len(&size_local);
  pvVar1 = malloc(size_local);
  if (pvVar1 == (void *)0x0) {
    snprintf(tmp42,0x800,"Failed to malloc size %d from %s %s:%d",size_local,file,func,line);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return pvVar1;
}

