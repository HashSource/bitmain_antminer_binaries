
/* WARNING: Unknown calling convention */

void * jsonp_malloc(size_t size)

{
  void *pvVar1;
  
  if (size != 0) {
    pvVar1 = (*do_malloc)(size);
    return pvVar1;
  }
  return (void *)0x0;
}

