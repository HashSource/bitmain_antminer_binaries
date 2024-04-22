
undefined4 des3_ctrl(int param_1,int param_2,undefined4 param_3,DES_cblock *param_4)

{
  int iVar1;
  
  if (param_2 != 6) {
    return 0xffffffff;
  }
  iVar1 = RAND_bytes(*param_4,*(int *)(param_1 + 0x58));
  if (0 < iVar1) {
    DES_set_odd_parity(param_4);
    if ((0xf < *(int *)(param_1 + 0x58)) &&
       (DES_set_odd_parity(param_4 + 1), 0x17 < *(int *)(param_1 + 0x58))) {
      DES_set_odd_parity(param_4 + 2);
      return 1;
    }
    return 1;
  }
  return 0;
}

