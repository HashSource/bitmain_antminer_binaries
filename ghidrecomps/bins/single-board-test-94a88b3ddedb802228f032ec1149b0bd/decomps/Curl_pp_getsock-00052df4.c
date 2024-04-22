
undefined4 Curl_pp_getsock(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x154);
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0x10000;
  }
  return uVar1;
}

