
void sha2_update(uint *param_1,void *param_2,uint param_3)

{
  void *__dest;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  size_t __n;
  
  if ((int)param_3 < 1) {
    return;
  }
  uVar3 = *param_1 & 0x3f;
  uVar1 = *param_1 + param_3;
  *param_1 = uVar1;
  uVar2 = uVar1;
  if (uVar1 < param_3) {
    uVar2 = param_1[1];
  }
  __n = 0x40 - uVar3;
  if (uVar1 < param_3) {
    uVar2 = uVar2 + 1;
  }
  if (uVar1 < param_3) {
    param_1[1] = uVar2;
  }
  uVar2 = uVar3;
  if (uVar3 != 0) {
    uVar2 = 1;
  }
  if ((int)param_3 < (int)__n) {
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    if (0x3f < (int)param_3) {
      do {
        param_3 = param_3 - 0x40;
        sha2_process(param_1,param_2);
        param_2 = (void *)((int)param_2 + 0x40);
joined_r0x0004523c:
      } while (0x3f < (int)param_3);
      if ((int)param_3 < 1) {
        return;
      }
    }
    (*(code *)PTR_memcpy_0007ce84)((int)param_1 + uVar3 + 0x28,param_2,param_3);
    return;
  }
  __dest = (void *)((int)(param_1 + 10) + uVar3);
  param_3 = param_3 - __n;
  uVar3 = 0;
  memcpy(__dest,param_2,__n);
  sha2_process(param_1,param_1 + 10);
  param_2 = (void *)((int)param_2 + __n);
  goto joined_r0x0004523c;
}

