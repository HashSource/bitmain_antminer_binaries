
void * jsonp_malloc(size_t size)

{
  void *pvVar1;
  size_t size_local;
  
  if (size == 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = (*do_malloc)(size);
  }
  return pvVar1;
}

