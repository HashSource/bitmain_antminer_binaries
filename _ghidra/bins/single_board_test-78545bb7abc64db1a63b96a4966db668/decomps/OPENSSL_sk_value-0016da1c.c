
undefined4 OPENSSL_sk_value(int *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 >> 0x1f;
  if (param_1 == (int *)0x0) {
    uVar1 = 1;
  }
  if (uVar1 == 0) {
    if ((int)param_2 < *param_1) {
      return *(undefined4 *)(param_1[1] + param_2 * 4);
    }
    return 0;
  }
  return 0;
}

