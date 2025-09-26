
undefined4 final_early_data(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      if (((((*(int *)(param_1 + 0xf50) != 0) && (*(int *)(param_1 + 0x8c) != 0)) &&
           (*(int *)(param_1 + 0x68) == 9)) &&
          ((*(int *)(param_1 + 0x5b0) != 0 && (*(int *)(param_1 + 0x44c) == 0)))) &&
         ((*(code **)(param_1 + 0xf80) == (code *)0x0 ||
          (iVar1 = (**(code **)(param_1 + 0xf80))(param_1,*(undefined4 *)(param_1 + 0xf84)),
          iVar1 != 0)))) {
        *(undefined4 *)(param_1 + 0x5ac) = 2;
        iVar1 = tls13_change_cipher_state(param_1,0x61);
        if (iVar1 == 0) {
          return 0;
        }
        return 1;
      }
      *(undefined4 *)(param_1 + 0x5ac) = 1;
      return 1;
    }
    if ((param_2 == 0x400) && (*(int *)(param_1 + 0x5b0) == 0)) {
      ossl_statem_fatal(param_1,0x2f,0x22c,0xe9,"ssl/statem/extensions.c",0x688);
      return 0;
    }
  }
  return 1;
}

