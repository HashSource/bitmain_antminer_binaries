
void jsonp_free(void *ptr)

{
  void *ptr_local;
  
  if (ptr != (void *)0x0) {
    (*do_free)(ptr);
  }
  return;
}

