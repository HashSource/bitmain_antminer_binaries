
void ssl3_send_next_proto(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint __n;
  size_t __n_00;
  
  if (*(int *)(param_1 + 0x34) == 0x1200) {
    __n = (uint)*(byte *)(param_1 + 0x178);
    puVar1 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
    __n_00 = 0x20 - (__n + 2 & 0x1f);
    puVar1[4] = *(byte *)(param_1 + 0x178);
    memcpy(puVar1 + 5,*(void **)(param_1 + 0x174),__n);
    puVar1[__n + 5] = (char)__n_00;
    memset(puVar1 + __n + 6,0,__n_00);
    puVar1[3] = (char)__n_00 + (char)(__n + 2);
    param_3 = 0x1201;
    *puVar1 = 0x43;
    puVar1[2] = (char)(__n_00 + __n + 2 >> 8);
    puVar1[1] = 0;
    *(size_t *)(param_1 + 0x44) = __n_00 + __n + 6;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0x1201;
  }
  ssl3_do_write(param_1,0x16,param_3,param_4);
  return;
}

