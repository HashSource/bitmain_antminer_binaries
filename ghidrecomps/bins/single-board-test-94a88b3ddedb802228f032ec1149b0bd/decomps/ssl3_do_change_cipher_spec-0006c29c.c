
undefined4 ssl3_do_change_cipher_spec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x34) & 0x2000) == 0) {
    uVar2 = 0x11;
  }
  else {
    uVar2 = 0x21;
  }
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x378) == 0) {
    iVar1 = *(int *)(param_1 + 0xc0);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x10) == 0)) {
      ERR_put_error(0x14,0x124,0x85,DAT_0006c350,0x676);
      return 0;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 100);
    *(undefined4 *)(iVar1 + 0xb4) = *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x344);
    iVar1 = (**(code **)(iVar3 + 8))();
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x10))(param_1,uVar2);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 100);
  if ((*(uint *)(param_1 + 0x34) & 0x1000) == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x20);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x28);
  }
  iVar1 = (**(code **)(iVar1 + 0x14))(param_1,uVar2);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0x124,0x44,DAT_0006c350,0x692);
    return 0;
  }
  *(int *)(*(int *)(param_1 + 0x58) + 0x338) = iVar1;
  return 1;
}

