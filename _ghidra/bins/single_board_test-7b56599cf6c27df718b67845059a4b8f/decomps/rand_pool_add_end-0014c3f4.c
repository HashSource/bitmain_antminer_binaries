
undefined4 rand_pool_add_end(int param_1,uint param_2,int param_3)

{
  if (param_2 <= (uint)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 4))) {
    if (param_2 != 0) {
      *(uint *)(param_1 + 4) = param_2 + *(int *)(param_1 + 4);
      *(int *)(param_1 + 0x1c) = param_3 + *(int *)(param_1 + 0x1c);
    }
    return 1;
  }
  ERR_put_error(0x24,0x72,0x7d,"crypto/rand/rand_lib.c",0x335);
  return 0;
}

