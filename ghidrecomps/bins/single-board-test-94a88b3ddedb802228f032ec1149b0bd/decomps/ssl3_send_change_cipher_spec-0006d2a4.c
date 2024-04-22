
undefined4 ssl3_send_change_cipher_spec(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1[0xd] == param_2) {
    uVar1 = 1;
    iVar2 = 0;
    **(undefined **)(param_1[0xf] + 4) = 1;
    param_1[0x11] = 1;
    param_1[0xd] = param_3;
    param_1[0x12] = 0;
  }
  else {
    iVar2 = param_1[0x12];
    uVar1 = param_1[0x11];
  }
  iVar2 = ssl3_write_bytes(param_1,0x14,*(int *)(param_1[0xf] + 4) + iVar2,uVar1);
  if (iVar2 < 0) {
    uVar1 = 0xffffffff;
  }
  else if (iVar2 == param_1[0x11]) {
    uVar1 = 1;
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])
                (1,*param_1,0x14,*(undefined4 *)(param_1[0xf] + 4),iVar2 + param_1[0x12],param_1,
                 param_1[0x1a]);
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
    param_1[0x11] = param_1[0x11] - iVar2;
    param_1[0x12] = param_1[0x12] + iVar2;
  }
  return uVar1;
}

