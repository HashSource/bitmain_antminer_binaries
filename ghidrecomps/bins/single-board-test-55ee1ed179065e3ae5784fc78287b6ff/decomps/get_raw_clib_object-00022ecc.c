
undefined4 get_raw_clib_object(void **param_1,void **param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = malloc((size_t)param_1[1]);
  *param_2 = pvVar1;
  if (*param_2 == (void *)0x0) {
    uVar2 = 3;
  }
  else {
    memcpy(*param_2,*param_1,(size_t)param_1[1]);
    uVar2 = 0;
  }
  return uVar2;
}

