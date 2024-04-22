
void * jsonp_strndup(void *param_1,size_t param_2)

{
  void *__dest;
  
  if (param_2 + 1 == 0) {
    return (void *)0x0;
  }
  __dest = (void *)(*do_malloc)(param_2 + 1);
  if (__dest != (void *)0x0) {
    memcpy(__dest,param_1,param_2);
    *(undefined *)((int)__dest + param_2) = 0;
    return __dest;
  }
  return (void *)0x0;
}

