
bool gost_digests(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    *param_3 = DAT_000df17c;
    return (bool)2;
  }
  if (param_4 != 0x329) {
    uVar1 = DAT_000df178;
    if (param_4 != 0x32f) {
      uVar1 = 0;
    }
    *param_2 = uVar1;
    return param_4 == 0x32f;
  }
  *param_2 = DAT_000df180;
  return true;
}

