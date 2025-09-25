
undefined4 SSL_get0_dane_authority(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == -0x94) {
    return 0xffffffff;
  }
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x98));
  if ((0 < iVar1) && (*(int *)(param_1 + 0x4d8) == 0)) {
    if (*(int *)(param_1 + 0xa0) != 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(param_1 + 0xa4);
      }
      if (param_3 != (undefined4 *)0x0) {
        if (*(int *)(param_1 + 0xa4) == 0) {
          uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc);
        }
        else {
          uVar2 = 0;
        }
        *param_3 = uVar2;
      }
    }
    return *(undefined4 *)(param_1 + 0xac);
  }
  return 0xffffffff;
}

