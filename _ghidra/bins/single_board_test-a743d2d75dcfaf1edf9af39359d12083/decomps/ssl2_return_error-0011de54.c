
void ssl2_return_error(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 uVar2;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  if (param_1[0x35] == 0) {
    param_1[0x36] = param_2;
    local_14 = 0;
    local_12 = (undefined1)param_2;
    local_13 = (undefined1)((uint)param_2 >> 8);
    iVar1 = ssl2_write(param_1,&local_14,3);
    uVar2 = extraout_r3;
    if (iVar1 < 0) {
      uVar2 = 3;
    }
    if (iVar1 < 0) {
      param_1[0x35] = uVar2;
    }
    else {
      param_1[0x35] = 3 - iVar1;
      if ((3 - iVar1 == 0) && ((code *)param_1[0x19] != (code *)0x0)) {
        (*(code *)param_1[0x19])(1,*param_1,0,&local_14,3,param_1,param_1[0x1a]);
      }
    }
  }
  return;
}

