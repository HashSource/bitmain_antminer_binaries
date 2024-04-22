
undefined4 get_mac(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = get_eth_mac(&DAT_0002ba3c,param_1);
  }
  return uVar1;
}

