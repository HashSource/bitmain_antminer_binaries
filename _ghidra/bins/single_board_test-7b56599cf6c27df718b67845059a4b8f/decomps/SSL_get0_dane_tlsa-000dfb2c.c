
undefined4
SSL_get0_dane_tlsa(int param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,
                  undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  
  if (((param_1 != -0x94) && (iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x98)), 0 < iVar1))
     && (*(int *)(param_1 + 0x4d8) == 0)) {
    if (*(undefined1 **)(param_1 + 0xa0) != (undefined1 *)0x0) {
      if (param_2 != (undefined1 *)0x0) {
        *param_2 = **(undefined1 **)(param_1 + 0xa0);
      }
      if (param_3 != (undefined1 *)0x0) {
        *param_3 = *(undefined1 *)(*(int *)(param_1 + 0xa0) + 1);
      }
      if (param_4 != (undefined1 *)0x0) {
        *param_4 = *(undefined1 *)(*(int *)(param_1 + 0xa0) + 2);
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 4);
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 8);
      }
    }
    return *(undefined4 *)(param_1 + 0xac);
  }
  return 0xffffffff;
}

