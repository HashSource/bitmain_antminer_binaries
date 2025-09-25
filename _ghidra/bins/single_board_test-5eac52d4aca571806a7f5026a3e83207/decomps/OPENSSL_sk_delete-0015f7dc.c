
undefined4 OPENSSL_sk_delete(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = param_2 >> 0x1f;
  if (param_1 == (uint *)0x0) {
    uVar1 = 1;
  }
  if (uVar1 == 0) {
    uVar1 = *param_1;
    if ((int)param_2 < (int)uVar1) {
      uVar4 = param_1[1];
      uVar2 = uVar1 - 1;
      uVar3 = *(undefined4 *)(uVar4 + param_2 * 4);
      if (param_2 != uVar2) {
        memmove((void *)(uVar4 + param_2 * 4),(void *)(param_2 * 4 + 4 + uVar4),
                ((uVar1 - param_2) + -1) * 4);
        uVar2 = *param_1 - 1;
      }
      *param_1 = uVar2;
      return uVar3;
    }
    return 0;
  }
  return 0;
}

