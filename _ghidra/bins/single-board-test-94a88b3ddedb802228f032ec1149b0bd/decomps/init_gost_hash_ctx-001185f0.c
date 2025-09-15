
undefined4 init_gost_hash_ctx(void *param_1,undefined4 param_2)

{
  void *pvVar1;
  
  memset(param_1,0,0x70);
  pvVar1 = malloc(0x1020);
  *(void **)((int)param_1 + 8) = pvVar1;
  if (pvVar1 != (void *)0x0) {
    gost_init(pvVar1,param_2);
    return 1;
  }
  return 0;
}

