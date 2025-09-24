
int ssl3_do_change_cipher_spec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar2 = 0x11;
  }
  else {
    uVar2 = 0x21;
  }
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x22c) == 0) {
    iVar1 = *(int *)(param_1 + 0x474);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 4) == 0)) {
      ERR_put_error(0x14,0x124,0x85,"ssl/s3_msg.c",0x18);
      return 0;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 4) + 100);
    *(undefined4 *)(iVar1 + 0x1b8) = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x210);
    iVar1 = (**(code **)(iVar3 + 8))();
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x10))(param_1,uVar2);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

