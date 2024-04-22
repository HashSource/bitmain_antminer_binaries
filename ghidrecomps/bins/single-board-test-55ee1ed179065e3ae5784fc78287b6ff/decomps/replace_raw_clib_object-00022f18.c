
void replace_raw_clib_object(void **param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  
  free(*param_1);
  pvVar1 = malloc(param_3);
  *param_1 = pvVar1;
  memcpy(*param_1,param_2,param_3);
  return;
}

