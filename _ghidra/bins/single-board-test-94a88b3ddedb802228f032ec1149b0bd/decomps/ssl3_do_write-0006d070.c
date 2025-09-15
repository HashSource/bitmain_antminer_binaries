
undefined4 ssl3_do_write(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ssl3_write_bytes(param_1,param_2,*(int *)(param_1[0xf] + 4) + param_1[0x12],param_1[0x11])
  ;
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (param_2 == 0x16) {
      ssl3_finish_mac(param_1,*(int *)(param_1[0xf] + 4) + param_1[0x12],iVar1);
    }
    if (param_1[0x11] == iVar1) {
      uVar2 = 1;
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])
                  (1,*param_1,param_2,*(undefined4 *)(param_1[0xf] + 4),iVar1 + param_1[0x12],
                   param_1,param_1[0x1a]);
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
      param_1[0x11] = param_1[0x11] - iVar1;
      param_1[0x12] = param_1[0x12] + iVar1;
    }
  }
  return uVar2;
}

