
undefined4 final_renegotiate(int param_1,undefined4 param_2,int param_3)

{
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (param_3 == 0 && (*(uint *)(param_1 + 0x4ec) & 0x40004) == 0) {
      ossl_statem_fatal(param_1,0x28,0x1e3,0x152,"ssl/statem/extensions.c",0x380);
      return 0;
    }
  }
  else if ((*(int *)(param_1 + 0x5ec) != 0) &&
          (((uint)(param_3 == 0) & (*(uint *)(param_1 + 0x4ec) ^ 0x40000) >> 0x12) != 0)) {
    ossl_statem_fatal(param_1,0x28,0x1e3,0x152,"ssl/statem/extensions.c",0x38c);
    return 0;
  }
  return 1;
}

