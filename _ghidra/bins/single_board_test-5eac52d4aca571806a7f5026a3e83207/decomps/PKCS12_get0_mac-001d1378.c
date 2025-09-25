
void PKCS12_get0_mac(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4
                    ,int param_5)

{
  if (*(undefined4 **)(param_5 + 4) == (undefined4 *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    X509_SIG_get0(**(undefined4 **)(param_5 + 4),param_2,param_1,param_4,param_4);
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(*(int *)(param_5 + 4) + 4);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(*(int *)(param_5 + 4) + 8);
      return;
    }
  }
  return;
}

