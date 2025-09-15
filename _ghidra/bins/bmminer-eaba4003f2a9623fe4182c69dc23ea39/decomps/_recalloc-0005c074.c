
void _recalloc(void **ptr,size_t old,size_t news,char *file,char *func,int line)

{
  void *pvVar1;
  char *file_local;
  size_t news_local;
  size_t old_local;
  void **ptr_local;
  
  if (news != old) {
    pvVar1 = _cgrealloc(*ptr,news,file,func,line);
    *ptr = pvVar1;
    if (old < news) {
      memset((void *)((int)*ptr + old),0,news - old);
    }
  }
  return;
}

