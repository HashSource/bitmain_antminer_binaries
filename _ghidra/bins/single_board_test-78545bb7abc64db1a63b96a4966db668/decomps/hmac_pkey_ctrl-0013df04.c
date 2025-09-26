
undefined4 hmac_pkey_ctrl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 3) {
    uVar1 = 1;
    *param_4 = 0x2a0;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

