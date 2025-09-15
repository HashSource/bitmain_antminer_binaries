
undefined4 des_ctrl(undefined4 param_1,int param_2,undefined4 param_3,DES_cblock *param_4)

{
  int iVar1;
  
  if (param_2 != 6) {
    return 0xffffffff;
  }
  iVar1 = RAND_bytes(*param_4,8);
  if (0 < iVar1) {
    DES_set_odd_parity(param_4);
    return 1;
  }
  return 0;
}

