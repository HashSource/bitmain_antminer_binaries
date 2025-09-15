
undefined4 json_array_insert_new(int *param_1,uint param_2,int *param_3)

{
  void *__src;
  int iVar1;
  size_t __n;
  
  if (param_3 == (int *)0x0) {
    return 0xffffffff;
  }
  if ((((param_1 != (int *)0x0) && (*param_1 == 1 && param_3 != param_1)) &&
      (param_2 <= (uint)param_1[3])) &&
     (__src = (void *)json_array_grow(param_1,1), __src != (void *)0x0)) {
    if (__src == (void *)param_1[4]) {
      iVar1 = (param_2 + 1) * 4;
      __n = iVar1 - 4;
      memmove((void *)(iVar1 + (int)__src),(void *)((int)__src + __n),(param_1[3] - param_2) * 4);
    }
    else {
      __n = param_2 * 4;
      memcpy((void *)param_1[4],__src,__n);
      memcpy((void *)(__n + 4 + param_1[4]),(void *)((int)__src + __n),(param_1[3] - param_2) * 4);
      jsonp_free(__src);
    }
    iVar1 = param_1[3];
    *(int **)(param_1[4] + __n) = param_3;
    param_1[3] = iVar1 + 1;
    return 0;
  }
  if ((param_3[1] != -1) && (iVar1 = param_3[1] + -1, param_3[1] = iVar1, iVar1 == 0)) {
    json_delete(param_3);
  }
  return 0xffffffff;
}

