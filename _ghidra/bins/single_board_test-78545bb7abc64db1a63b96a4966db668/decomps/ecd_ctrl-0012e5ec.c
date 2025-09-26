
undefined4 ecd_ctrl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 3) {
    uVar1 = 2;
    *param_4 = 0;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

