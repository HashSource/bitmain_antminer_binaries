
undefined4 tls1_get_server_method(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x303) {
    return DAT_0006fe7c;
  }
  if (param_1 != 0x302) {
    uVar1 = DAT_0006fe78;
    if (param_1 != 0x301) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return DAT_0006fe80;
}

