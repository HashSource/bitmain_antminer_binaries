
void sha256_update(int *param_1,void *param_2,uint param_3)

{
  uint __n;
  
  __n = param_3;
  if (0x40U - param_1[1] < param_3) {
    __n = 0x40U - param_1[1];
  }
  memcpy((void *)((int)param_1 + param_1[1] + 8),param_2,__n);
  if (param_1[1] + param_3 < 0x40) {
    param_1[1] = param_1[1] + param_3;
  }
  else {
    param_3 = param_3 - __n;
    sha256_transf(param_1,param_1 + 2,1);
    sha256_transf(param_1,(int)param_2 + __n,param_3 >> 6);
    memcpy(param_1 + 2,(void *)((int)param_2 + __n + (param_3 & 0xffffffc0)),param_3 & 0x3f);
    param_1[1] = param_3 & 0x3f;
    *param_1 = *param_1 + ((param_3 >> 6) + 1) * 0x40;
  }
  return;
}

