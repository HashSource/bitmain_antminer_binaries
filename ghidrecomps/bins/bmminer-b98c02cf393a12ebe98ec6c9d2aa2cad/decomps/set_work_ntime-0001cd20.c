
void set_work_ntime(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  *(uint *)(param_1 + 0x44) =
       param_2 << 0x18 | (param_2 >> 8 & 0xff) << 0x10 | (param_2 >> 0x10 & 0xff) << 8 |
       param_2 >> 0x18;
  if (*(void **)(param_1 + 0x134) != (void *)0x0) {
    free(*(void **)(param_1 + 0x134));
    uVar1 = bin2hex(param_1 + 0x44,4);
    *(undefined4 *)(param_1 + 0x134) = uVar1;
  }
  return;
}

