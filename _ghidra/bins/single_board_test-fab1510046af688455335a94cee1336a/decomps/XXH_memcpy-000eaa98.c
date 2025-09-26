
void * XXH_memcpy(void *dest,void *src,size_t size)

{
  void *pvVar1;
  size_t size_local;
  void *src_local;
  void *dest_local;
  
  pvVar1 = memcpy(dest,src,size);
  return pvVar1;
}

