
undefined4 final_psk(int param_1,undefined4 param_2,int param_3)

{
  if (((*(int *)(param_1 + 0x1c) != 0 && param_3 != 0) && (*(int *)(param_1 + 0x5c8) != 0)) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x5c8) + 0x268) + 0x1b8) == 0)) {
    ossl_statem_fatal(param_1,0x6d,0x27f,0x136,"ssl/statem/extensions.c",0x6ce);
    return 0;
  }
  return 1;
}

