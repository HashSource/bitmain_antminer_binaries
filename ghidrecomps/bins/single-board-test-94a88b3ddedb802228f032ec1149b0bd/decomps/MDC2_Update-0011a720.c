
undefined4 MDC2_Update(size_t *param_1,void *param_2,size_t param_3,undefined4 param_4)

{
  size_t sVar1;
  size_t __n;
  uint uVar2;
  
  sVar1 = *param_1;
  if (sVar1 != 0) {
    if (param_3 + sVar1 < 8) {
      memcpy((void *)((int)param_1 + sVar1 + 4),param_2,param_3);
      *param_1 = *param_1 + param_3;
      return 1;
    }
    __n = 8 - sVar1;
    memcpy((void *)((int)param_1 + sVar1 + 4),param_2,__n);
    *param_1 = 0;
    param_3 = param_3 - __n;
    param_2 = (void *)((int)param_2 + __n);
    mdc2_body(param_1,param_1 + 1,8,0,param_4);
  }
  uVar2 = param_3 & 0xfffffff8;
  if (uVar2 != 0) {
    mdc2_body(param_1,param_2,uVar2);
  }
  param_3 = param_3 - uVar2;
  if (param_3 == 0) {
    return 1;
  }
  memcpy(param_1 + 1,(void *)((int)param_2 + uVar2),param_3);
  *param_1 = param_3;
  return 1;
}

