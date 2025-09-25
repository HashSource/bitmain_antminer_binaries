
undefined4 OPENSSL_sk_set(int *param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_2 >> 0x1f;
  if (param_1 == (int *)0x0) {
    uVar2 = 1;
  }
  if (uVar2 == 0) {
    if ((int)param_2 < *param_1) {
      *(undefined4 *)(param_1[1] + param_2 * 4) = param_3;
      param_1[2] = 0;
      uVar1 = *(undefined4 *)(param_1[1] + param_2 * 4);
    }
    else {
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0;
}

