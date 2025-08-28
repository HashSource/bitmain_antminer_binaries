
int * new_clib_object(void *param_1,size_t param_2)

{
  int *__ptr;
  void *pvVar1;
  
  __ptr = (int *)malloc(8);
  if (__ptr == (int *)0x0) {
    __ptr = (int *)0x0;
  }
  else {
    __ptr[1] = param_2;
    pvVar1 = malloc(param_2);
    *__ptr = (int)pvVar1;
    if (*__ptr == 0) {
      free(__ptr);
      __ptr = (int *)0x0;
    }
    else {
      memcpy((void *)*__ptr,param_1,param_2);
    }
  }
  return __ptr;
}

