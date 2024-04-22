
undefined4 json_array_extend(int *param_1,int *param_2)

{
  int iVar1;
  int *__src;
  size_t sVar2;
  size_t __n;
  int *piVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (((*param_1 == 1 && param_2 != (int *)0x0) && (*param_2 == 1)) &&
     (iVar1 = json_array_grow(param_1,param_2[3]), iVar1 != 0)) {
    sVar2 = param_2[3];
    __src = (int *)param_2[4];
    __n = sVar2;
    if (sVar2 != 0) {
      __n = sVar2 * 4;
      piVar3 = __src;
      do {
        piVar4 = piVar3 + 1;
        iVar1 = *piVar3;
        if (iVar1 != 0) {
          if (*(int *)(iVar1 + 4) != -1) {
            *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
          }
        }
        piVar3 = piVar4;
      } while (piVar4 != __src + sVar2);
    }
    memcpy((void *)(param_1[4] + param_1[3] * 4),__src,__n);
    param_1[3] = param_2[3] + param_1[3];
    return 0;
  }
  return 0xffffffff;
}

