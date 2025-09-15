
void * jsonp_strdup(char *param_1)

{
  size_t sVar1;
  void *__dest;
  
  sVar1 = strlen(param_1);
  if (sVar1 == 0xffffffff) {
    __dest = (void *)0x0;
  }
  else {
    __dest = (void *)jsonp_malloc(sVar1 + 1);
    if (__dest == (void *)0x0) {
      __dest = (void *)0x0;
    }
    else {
      memcpy(__dest,param_1,sVar1 + 1);
    }
  }
  return __dest;
}

