
void OSSL_STORE_ctrl(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  OSSL_STORE_vctrl(param_1,param_2,&uStack_8);
  return;
}

