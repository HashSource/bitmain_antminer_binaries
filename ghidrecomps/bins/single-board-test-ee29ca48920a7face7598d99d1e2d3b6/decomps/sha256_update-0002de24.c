
void sha256_update(int *param_1,void *param_2,uint param_3)

{
  uint __n;
  uint uVar1;
  uint __n_00;
  
  __n = param_3;
  if (0x40U - param_1[1] <= param_3) {
    __n = 0x40U - param_1[1];
  }
  memcpy((void *)(param_1[1] + 8 + (int)param_1),param_2,__n);
  if (param_3 + param_1[1] < 0x40) {
    param_1[1] = param_1[1] + param_3;
  }
  else {
    uVar1 = param_3 - __n >> 6;
    sha256_transf(param_1,param_1 + 2,1);
    sha256_transf(param_1,__n + (int)param_2,uVar1);
    __n_00 = param_3 - __n & 0x3f;
    memcpy(param_1 + 2,(void *)(uVar1 * 0x40 + __n + (int)param_2),__n_00);
    param_1[1] = __n_00;
    *param_1 = *param_1 + (uVar1 + 1) * 0x40;
  }
  return;
}

