
undefined4 strbuffer_append_bytes(int *param_1,void *param_2,uint param_3)

{
  void *__dest;
  uint uVar1;
  uint uVar2;
  
  if ((uint)(param_1[2] - param_1[1]) <= param_3) {
    if (((param_1[2] < 0) || (param_3 == 0xffffffff)) || (-param_3 - 2 < (uint)param_1[1])) {
      return 0xffffffff;
    }
    uVar1 = param_1[1] + param_3 + 1;
    uVar2 = param_1[2] << 1;
    if ((uint)(param_1[2] << 1) <= uVar1) {
      uVar2 = uVar1;
    }
    __dest = (void *)jsonp_malloc(uVar2);
    if (__dest == (void *)0x0) {
      return 0xffffffff;
    }
    memcpy(__dest,(void *)*param_1,param_1[1]);
    jsonp_free(*param_1);
    *param_1 = (int)__dest;
    param_1[2] = uVar2;
  }
  memcpy((void *)(*param_1 + param_1[1]),param_2,param_3);
  param_1[1] = param_1[1] + param_3;
  *(undefined1 *)(*param_1 + param_1[1]) = 0;
  return 0;
}

