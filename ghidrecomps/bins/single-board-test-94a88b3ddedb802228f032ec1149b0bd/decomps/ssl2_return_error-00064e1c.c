
void ssl2_return_error(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  
  iVar2 = param_1[0x35];
  if (iVar2 == 0) {
    param_1[0x36] = param_2;
    local_14 = 0;
    local_12 = (undefined)param_2;
    local_13 = (undefined)((uint)param_2 >> 8);
    iVar1 = ssl2_write(param_1,&local_14,3);
    if (iVar1 < 0) {
      iVar2 = 3;
    }
    if (iVar1 < 0) {
      param_1[0x35] = iVar2;
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

