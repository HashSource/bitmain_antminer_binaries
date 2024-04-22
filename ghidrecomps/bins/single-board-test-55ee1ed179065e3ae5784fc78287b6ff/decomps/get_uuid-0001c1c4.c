
undefined4 get_uuid(void *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    memset(param_1,0,0x10);
    uVar1 = get_eth_mac(&DAT_0002ba3c,param_1);
  }
  return uVar1;
}

