
bool gost_ciphers(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    *param_3 = DAT_000df1b8;
    return (bool)2;
  }
  if (param_4 != 0x32d) {
    uVar1 = DAT_000df1b4;
    if (param_4 != 0x32e) {
      uVar1 = 0;
    }
    *param_2 = uVar1;
    return param_4 == 0x32e;
  }
  *param_2 = DAT_000df1bc;
  return true;
}

