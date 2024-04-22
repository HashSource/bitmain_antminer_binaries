
void ** new_clib_object(void *param_1,void *param_2)

{
  void **__ptr;
  void *pvVar1;
  
  __ptr = (void **)malloc(8);
  if (__ptr == (void **)0x0) {
    __ptr = (void **)0x0;
  }
  else {
    __ptr[1] = param_2;
    pvVar1 = malloc((size_t)param_2);
    *__ptr = pvVar1;
    if (*__ptr == (void *)0x0) {
      free(__ptr);
      __ptr = (void **)0x0;
    }
    else {
      memcpy(*__ptr,param_1,(size_t)param_2);
    }
  }
  return __ptr;
}

