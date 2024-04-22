
undefined4 strbuffer_append_bytes(void **param_1,void *param_2,uint param_3)

{
  void *pvVar1;
  void *pvVar2;
  
  if ((uint)((int)param_1[2] - (int)param_1[1]) <= param_3) {
    if ((((int)param_1[2] < 0) || (param_3 == 0xffffffff)) || ((void *)(-2 - param_3) < param_1[1]))
    {
      return 0xffffffff;
    }
    pvVar1 = (void *)((int)param_1[1] + param_3 + 1);
    pvVar2 = (void *)((int)param_1[2] << 1);
    if ((void *)((int)param_1[2] << 1) <= pvVar1) {
      pvVar2 = pvVar1;
    }
    pvVar1 = (void *)jsonp_malloc(pvVar2);
    if (pvVar1 == (void *)0x0) {
      return 0xffffffff;
    }
    memcpy(pvVar1,*param_1,(size_t)param_1[1]);
    jsonp_free(*param_1);
    *param_1 = pvVar1;
    param_1[2] = pvVar2;
  }
  memcpy((void *)((int)*param_1 + (int)param_1[1]),param_2,param_3);
  param_1[1] = (void *)((int)param_1[1] + param_3);
  *(undefined *)((int)*param_1 + (int)param_1[1]) = 0;
  return 0;
}

