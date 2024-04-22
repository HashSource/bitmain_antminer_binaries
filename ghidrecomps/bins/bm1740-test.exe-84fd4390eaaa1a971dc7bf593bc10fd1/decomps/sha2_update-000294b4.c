
void sha2_update(uint *param_1,void *param_2,uint param_3)

{
  size_t __n;
  uint local_1c;
  void *local_18;
  uint local_c;
  
  if (0 < (int)param_3) {
    local_c = *param_1 & 0x3f;
    __n = 0x40 - local_c;
    *param_1 = *param_1 + param_3;
    *param_1 = *param_1;
    if (*param_1 < param_3) {
      param_1[1] = param_1[1] + 1;
    }
    local_1c = param_3;
    local_18 = param_2;
    if ((local_c != 0) && ((int)__n <= (int)param_3)) {
      memcpy((void *)((int)param_1 + local_c + 0x28),param_2,__n);
      sha2_process(param_1,param_1 + 10);
      local_18 = (void *)((int)param_2 + __n);
      local_1c = param_3 - __n;
      local_c = 0;
    }
    for (; 0x3f < (int)local_1c; local_1c = local_1c - 0x40) {
      sha2_process(param_1,local_18);
      local_18 = (void *)((int)local_18 + 0x40);
    }
    if (0 < (int)local_1c) {
      memcpy((void *)((int)param_1 + local_c + 0x28),local_18,local_1c);
    }
  }
  return;
}

