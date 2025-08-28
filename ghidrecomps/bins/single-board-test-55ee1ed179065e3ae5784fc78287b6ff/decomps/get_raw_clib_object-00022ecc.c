
undefined4 get_raw_clib_object(undefined4 *param_1,int *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = malloc(param_1[1]);
  *param_2 = (int)pvVar1;
  if (*param_2 == 0) {
    uVar2 = 3;
  }
  else {
    memcpy((void *)*param_2,(void *)*param_1,param_1[1]);
    uVar2 = 0;
  }
  return uVar2;
}

