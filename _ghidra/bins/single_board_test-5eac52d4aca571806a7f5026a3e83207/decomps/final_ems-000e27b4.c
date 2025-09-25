
undefined4 final_ems(int param_1)

{
  undefined4 uVar1;
  
  if ((**(uint **)(param_1 + 0x7c) & 0x1200) == 0x1000) {
    uVar1 = 0;
    ossl_statem_fatal(param_1,0x28,0x1e6,0x68,"ssl/statem/extensions.c",0x4b4);
  }
  else {
    if (((*(int *)(param_1 + 0x1c) == 0) && (*(int *)(param_1 + 0x8c) != 0)) &&
       (((**(uint **)(param_1 + 0x7c) ^ 0x200) << 0x16) >> 0x1f !=
        (*(uint *)(*(int *)(param_1 + 0x474) + 0x1fc) & 1 ^ 1))) {
      ossl_statem_fatal(param_1,0x28,0x1e6,0x68,"ssl/statem/extensions.c",0x4bf);
      return 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}

