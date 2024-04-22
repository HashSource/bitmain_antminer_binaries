
undefined4 strbuffer_append_bytes(void **param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar2 = param_1[1];
  pvVar1 = param_1[2];
  if (param_3 < (uint)((int)pvVar1 - (int)pvVar2)) {
    pvVar1 = *param_1;
LAB_00051e28:
    memcpy((void *)((int)pvVar1 + (int)pvVar2),param_2,param_3);
    pvVar1 = param_1[1];
    param_1[1] = (void *)(param_3 + (int)pvVar1);
    *(undefined *)((int)*param_1 + (int)(void *)(param_3 + (int)pvVar1)) = 0;
    return 0;
  }
  if ((((uint)(param_3 == 0xffffffff) | (uint)pvVar1 >> 0x1f) == 0) &&
     (pvVar2 <= (void *)(-2 - param_3))) {
    pvVar2 = (void *)((int)pvVar2 + param_3 + 1);
    pvVar3 = (void *)((int)pvVar1 << 1);
    if ((void *)((int)pvVar1 << 1) < pvVar2) {
      pvVar3 = pvVar2;
    }
    pvVar1 = (void *)jsonp_malloc(pvVar3);
    if (pvVar1 != (void *)0x0) {
      memcpy(pvVar1,*param_1,(size_t)param_1[1]);
      jsonp_free(*param_1);
      pvVar2 = param_1[1];
      *param_1 = pvVar1;
      param_1[2] = pvVar3;
      goto LAB_00051e28;
    }
  }
  return 0xffffffff;
}

